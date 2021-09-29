import cv2
import numpy as np 
import time
print(cv2.__version__)
dispW=1280*1/2
dispH=720*1/2
flip=2
font=cv2.FONT_HERSHEY_DUPLEX
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
cam2=cv2.VideoCapture(2)
cam1=cv2.VideoCapture(1)
startTime=time.time()
while True:
    
    ret, frame1=cam1.read()
    ret, frame2=cam2.read()
    frame2=cv2.resize(frame2,(frame1.shape[1],frame1.shape[0]))
    frameCombined=np.hstack(frame1,frame2)
    dt=time.time()-startTime
    cv2.imshow('piCam',frame1)
    startTime=time.time
    dtav=.9*dtac+.1*dt
    fps=1/dtav
    cv2.rectangle(frameCombined,(0,0),(130,40),(100,100,100),-1)
    cv2.putText(frameCombined,str(round(fps,1))+' FPS',(0,25),font,.75,(0,255,255),2)
    cv2.moveWindow('piCam',0,0)
    cv2.imshow('nanoCam',frame2)
    cv2.moveWindow('nanoCam',0,720)
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        break
cam.release()
cv2.destroyAllWindows()