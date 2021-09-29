from threading import Thread
import cv2
import time
import numpy as np 
import face_recognition
import pickle

font=cv2.FONT_HERSHEY_SIMPLEX

with open('train.pkl','rb') as f:
        Names=pickle.load(f)
        Encodings=pickle.load(f)



class vStream:
    def __init__(self,src,width,height):
        self.width=width
        self.height=height
        self.capture=cv2.VideoCapture(src)
        self.thread=Thread(target=self.update,args=())
        self.thread.daemon=True
        self.thread.start()

    def update(self):
        while True:
            _,self.frame=self.capture.read()
            self.frame2=cv2.resize(self.frame,(self.width,self.height))
    def getFrame(self):
        return self.frame2
dispW=640
dispH=480
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
cam1=vStream(0,dispW,dispH)
cam2=vStream(1,dispW,dispH)
font=cv2.FONT_HERSHEY_DUPLEX

dtav=0

scaleFactor=.3

startTime=time.time()
while True:
    try:
        myFrame1=cam1.getFrame()
        myFrame2=cam2.getFrame()
        myFrame3=np.hstack((myFrame1,myFrame2))
        frameRGB=cv2.cvtColor(myFrame3,cv2.COLOR_BGR2RGB)
        frameRGBsmall=cv2.resize(frameRGB,(0,0),fx=scaleFactor,fy=scaleFactor)
        facePositions=cv2.face_recognition.face_locations( frameRGBsmall, model='hog')
        for (top,right,bottom,left),face_encoding in zip(facePositions,Encodings):
            name='random dude'
            matches=face_recognition.compare_faces(Encodings,face_encoding)
            if True in matches:
                first_match_index=matches.index(True)
                name=Names[first_match_index]
                print(name)
            top=int(top/scaleFactor)
            left=int(left/scaleFactor)
            right=int(right/scaleFactor)
            bottom=int(bottom/scaleFactor)
            cv2.retangle(myFrame3,(left,top),(right,bottom),(255,100,255),2)
            cv2.putText(myFrame3,name,(left,top-6),font,.75(0,255,255),2)
        allEncodings=face_recognition.face_encodings(frameRGBsmall,facePositions)
        dt=time.time() - startTime
        startTime=time.time()
        dtav=.9*dtav+.1*dt
        fps=1/dtav
        cv2.retangle(myFrame3,(0,0),(100,40),(0,0,255),-1)
        cv2.putText(myFrame3,str(round(fps,1))+'fps ',(0,25),font,.75,(100,100,100),2)
        cv2.imshow("combined",myFrame3)
        cv2.moveWindow("combined",0,0)   
    except:
        print('frame not available')
    
    if cv2.waitKey(1)==ord('q'):
        cam1.capture.release()
        cam2.capture.release()    
        cv2.destroyAllWindows()
        exit(1)
        break