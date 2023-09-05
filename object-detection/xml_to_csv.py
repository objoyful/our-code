import os
import glob
import pandas as pd
import xml.etree.ElementTree as ET


def xml_to_csv(path):
    xml_list = []
    for xml_file in glob.glob(path + '/*.xml'):
        tree = ET.parse(xml_file)
        root = tree.getroot()
        for member in root.findall('object'):
            full_path = os.path.join("object-detection", "downloads", root.find('filename').text) # type: ignore
            value = (root.find('filename').text, # type: ignore
                     int(root.find('size')[0].text), # type: ignore
                     int(root.find('size')[1].text), # type: ignore
                     member[0].text,
                     int(member[4][0].text), # type: ignore
                     int(member[4][1].text), # type: ignore
                     int(member[4][2].text), # type: ignore
                     int(member[4][3].text) # type: ignore
                     )
            xml_list.append(value)
    column_name = ['filename', 'width', 'height', 'class', 'xmin', 'ymin', 'xmax', 'ymax']
    xml_df = pd.DataFrame(xml_list, columns=column_name)
    return xml_df

def main():
    try:
        os.makedirs(os.path.join("object-detection", "data"))
    except:
        pass

    for directory in ['train', 'test']:
        image_path = os.path.join(os.getcwd(), 'object-detection', 'downloads', directory)
        xml_df = xml_to_csv(image_path)

        csv_path = os.path.join('object-detection', 'data', '{}_labels.csv'.format(directory))
        xml_df.to_csv(csv_path, index=None) # type: ignore

        print('Successfully converted xml to csv.')
main()