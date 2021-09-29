import face_recognition
import cv2
import os
import pickle
import time
from face_recognition.api import face_encodings
print(cv2.__version__)
fpsReport=0
scaleFactor=1
Encodings=[]
Names=[]

with open('train.pkl','rb') as f:
    Names=pickle.load(f)
    Encodings=pickle.load(f)

font=cv2.FONT_HERSHEY_DUPLEX

cam=cv2.VideoCapture('/dev/video0')
timeStamp=time.time()
while True:
    _,frame=cam.read()
    frameSmall=cv2.resize(frame,(0,0),fx=.33,fy=scaleFactor)
    
    frameRGB=cv2.cvtColor(frameSmall,cv2.COLOR_BGR2RGB)
    
    facePositions=face_recognition.face_locations(frameRGB,model='hog')
    allEncodings=face_recognition.face_encodings(frameRGB,facePositions)
    
    for (top,right,bottom,left),face_encoding in zip(facePositions,allEncodings):
        name='ovo'
        matches=face_recognition.compare_faces(Encodings,face_encoding)
        if True in matches:
            first_match_index=matches.index(True)
            name=Names[first_match_index]
        top = int(top/scaleFactor)
        right = int(right/scaleFactor)
        bottom = int(bottom/scaleFactor)
        left = int(left/scaleFactor)
        cv2.rectangle(frame,(left,top),(right,bottom),(0,255,0),3)
        cv2.putText(frame, name, (left, top - 6), font, 0.75, (0, 255, 255), 2)
    dt=time.time()-timeStamp
    fps=1/dt
    fps=round(fpsReport,2)
    fpsReport=.90*fpsReport + .1*fps
    print('fps is:',fpsReport)
    timeStamp=time.time()
    cv2.rectangle(frame,(0,0),(100,40),(100,100,250),4)
    cv2.putText(frame,str(round(fpsReport,1)) + 'fps',(0,25),font,.75,(255,0,100,2))
    cv2.imshow('frame',frame)
    cv2.moveWindow('frame',0,0)

    if cv2.waitKey(1) == ord('q'):

        break
cv2.destroyAllWindows()