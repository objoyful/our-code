import time; start = time.perf_counter()
import pydicom as dicom # Read the dicom files
import os
import pandas as pd
import matplotlib.pyplot as plt
import cv2
import numpy as np
import math
from tqdm import tqdm
from multiprocessing import Pool

IMG_PX_SIZE = 50
HM_SLICES = 20
CORES = 8

dir = 'DSB3/'
data_dir = os.path.join(dir, 'stage1')
patients = os.listdir(data_dir)
labels_df = pd.read_csv(os.path.join(dir, 'stage1_labels.csv'), index_col=0)

def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]

def mean(l):
    return sum(l) / len(l)

def process_data(patient, labels_df, img_px_size=50, hm_slices=20, visualize=False):
    label = labels_df._get_value(patient, 'cancer')
    path = os.path.join(data_dir, patient)
    slices = [dicom.read_file(os.path.join(path, s)) for s in os.listdir(path)]
    slices.sort(key=lambda x: int(x.ImagePositionPatient[2]))
    
    new_slices = []
    slices = [cv2.resize(np.array(each_slice.pixel_array), (img_px_size, img_px_size)) for each_slice in slices]
    chunk_sizes = math.ceil(len(slices) / hm_slices)

    for slice_chunk in chunks(slices, chunk_sizes):
        slice_chunk = list(map(mean, zip(*slice_chunk)))
        new_slices.append(slice_chunk)
    
    while len(new_slices) < hm_slices:
        new_slices.append(new_slices[-1])
    
    while len(new_slices) > hm_slices:
        new_val = list(map(mean, zip(*[new_slices[-2], new_slices[-1]])))
        del new_slices[-1]
        new_slices[-1] = new_val
    
    if len(new_slices) != 20: print(len(new_slices)) 
    
    if visualize:
        fig = plt.figure()

        for num, each_slice in enumerate(new_slices):
            y = fig.add_subplot(4, 5, num + 1)
            y.imshow(each_slice)
        plt.show()
    
    if label == 1: label = np.array([0, 1])
    elif label == 0: label = np.array([1, 0])

    return np.array(new_slices), label

much_data = []

def get_patient_data(patient):
    try:
        img_data, label = process_data(patient, labels_df, img_px_size=IMG_PX_SIZE, hm_slices=HM_SLICES)
    except KeyError as e:
        print('This is unlabeled data.')

    return img_data, label

if __name__ == '__main__':
    with Pool(CORES) as p:
        much_data.append(p.map(get_patient_data, patients))
    
    much_data = much_data[0]

    try:
        os.makedirs('MachineLearning/ml71-data')
    except:
        pass

    np.save(os.path.join('MachineLearning', 'ml71-data', 'muchdata-{}-{}-{}.npy'.format(IMG_PX_SIZE, IMG_PX_SIZE, HM_SLICES)), np.array(much_data, dtype=object))

    print(time.perf_counter() - start)