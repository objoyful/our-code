from threading import Thread
import cv2
import numpy as np
import time

print('CV2 Version:', cv2.__version__)

class vStream:
    def __init__(self, src, width, height):
        self.width = width
        self.height = height
        
        self.capture = cv2.VideoCapture(src)

        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        
        self.thread = Thread(target = self.update, args = ())
        self.thread.daemon = True
        self.thread.start()
    
    def update(self):
        while True:
            self.ret, self.frame = self.capture.read()
            self.frame2 = cv2.resize(self.frame, (self.width, self.height))

    def getFrame(self):
        return self.frame2

dispW = 640
dispH = 480

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

cam1 = vStream(1, dispW, dispH)
cam2 = vStream(camSet, dispW, dispH)

font = cv2.FONT_HERSHEY_SIMPLEX
startTime = time.time()

dtav = 0

while True:
    try:
        myFrame1 = cam1.getFrame()
        myFrame2 = cam2.getFrame()
        myFrame3 = np.hstack((myFrame1, myFrame2))

        dt = time.time() - startTime
        startTime = time.time()

        dtav = 0.999 * dtav + 0.001 * dt
        fps = 1 / dtav

        cv2.rectangle(myFrame3, (0, 0), (140, 40), (0, 0, 255), -1)
        cv2.putText(myFrame3, str(round(fps, 1)) + ' FPS', (0, 25), font, 0.75, (0, 255, 255), 2)

        cv2.imshow('Combined Cam', myFrame3)
        cv2.moveWindow('Combined Cam', 0, 0)
    
    except:
        print("Frame not available")

    if cv2.waitKey(1) == ord('q'):
        cam1.capture.release()
        cam2.capture.release()

        cv2.destroyAllWindows()
        exit(1)

        break