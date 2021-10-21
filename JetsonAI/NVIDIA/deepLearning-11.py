import jetson.inference
import jetson.utils
import numpy as np
import time
from gtts import gTTS
import os
import threading

import cv2
print(cv2.__version__)

speak = True
item = 'Ready'
confidence = 0
itemOld = ''

def sayItem():
    global speak
    global item

    while True:
        if speak == True:
            output = gTTS(text = item, lang = 'en', slow = False)
            
            output.save('JetsonAI/NVIDIA/output.mp3')
            os.system('mpg123 JetsonAI/NVIDIA/output.mp3')
            
            speak = False

x = threading.Thread(target = sayItem, daemon = True)
x.start()

dispW = 1920
dispH = 1080

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(0)

# Web cam or pi cam setting
cam = webCam

cam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

net = jetson.inference.imageNet('googlenet')
font = cv2.FONT_HERSHEY_SIMPLEX

timeMark = time.time()
fpsFilter = 0

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGBA).astype(np.float32)
    img = jetson.utils.cudaFromNumpy(img)

    if speak == False:
        classID, confidence = net.Classify(img, dispW, dispH)

        if confidence >= 0.5:
            item = net.GetClassDesc(classID)
            
            if item != itemOld:
                speak = True
        
        if confidence < 0.5:
            item = ''
        
        itemOld = item


    dt = time.time() - timeMark
    timeMark = time.time()

    fps = 1 / dt
    fpsFilter = 0.95 * fpsFilter + 0.05 * fps

    cv2.putText(frame, str(round(fpsFilter, 1)) + ' FPS ' + item + ' ' + str(round(100 * confidence, 2)) + '%', (20, 20), font, 0.75, (0, 0, 255), 3)

    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()