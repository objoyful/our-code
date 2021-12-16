import jetson.inference
import jetson.utils
import cv2
import numpy as np
import time

dispW = 1920
dispH = 1080

width = dispW
height = dispH

cam = cv2.VideoCapture(1)

cam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

# display = jetson.utils.glDisplay()
net = jetson.inference.imageNet('alexnet', ['--model=/home/jetson/Downloads/jetson-inference/python/training/classification/myModel/resnet18.onnx', '--input_blob=input_0', '--output_blob=output_0', '--labels=/home/jetson/Downloads/jetson-inference/myTrain/labels.txt'])

timeMark = time.time()
fpsFilter = 0

font = cv2.FONT_HERSHEY_SIMPLEX

while True:
    ret, frame = cam.read()

    img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGBA).astype(np.float32)
    img = jetson.utils.cudaFromNumpy(img)

    classID, confidence = net.Classify(img, width, height)
    item = net.GetClassDesc(classID)

    dt = time.time() - timeMark
    fps = 1 / dt
    fpsFilter = 0.95 * fpsFilter + 0.05 * fps

    timeMark = time.time()

    # font.OverlayText(frame, width, height, str(round(fpsFilter, 1)) + ' FPS ' + item, 5, 5, font.Magenta, font.Blue)
    # display.RenderOnce(frame, width, height)

    # frame = jetson.utils.cudaToNumpy(frame, width, height, 4)
    # frame = cv2.cvtColor(frame, cv2.COLOR_RGBA2BGR).astype(np.uint8)

    cv2.putText(frame, str(round(fpsFilter, 1)) + ' FPS ' + item, (0, 30), font, 1, (0, 0, 255), 3)

    cv2.imshow('Recognize Cam', frame)
    cv2.moveWindow('Recognize Cam', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()