import cv2
import numpy as np
print(cv2.__version__)
randonvariablefornoreason=700
dispW=640
dispH=480
flip=2
img1=np.zeros((480,640,1),np.uint8)
img1[0:480,0:320]=[255]
img2=np.zeros((480,640,1),np.uint8)
img2[190:290,270:370]=[255]
bitAnd=cv2.bitwise_and(img1,img2)
bitOr=cv2.bitwise_or(img1,img2)
bitXor=cv2.bitwise_xor(img1,img2)
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
while True:
    
    ret, frame=cam.read()
    cv2.imshow('img1',img1)
    cv2.imshow('img2',img2)
    cv2.imshow('bitAnd',bitAnd)
    cv2.imshow('bitOr',bitOr)
    cv2.imshow('bitXor',bitXor)
    cv2.moveWindow('nanoCam',0,0)
    cv2.moveWindow('img1',0,480)
    cv2.moveWindow('img2',640,0)
    cv2.moveWindow('bitOr',640,450)
    cv2.moveWindow('bitAnd',1280,450)
    cv2.moveWindow('bitXor',1280,0)
    frame=cv2.bitwise_and(frame,frame,mask=bitXor)
    cv2.imshow('nanoCam',frame)
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        print('oof')
        break
cam.release()
cv2.destroyAllWindows()