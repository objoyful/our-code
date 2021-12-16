import cv2
print(cv2.__version__)
dispW=1280*1/2
dispH=720*1/2
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
from adafruit_servokit import ServoKit
kit=ServoKit(channels=16)
pan=90
tilt=90
kit.servo[0].angle=pan
kit.servo[1].angle=tilt
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
face_cascade=cv2.CascadeClassifier('/home/jetson2/Code/JetsonAI-2/cascade/face.xml')
eye_cascade=cv2.CascadeClassifier('/home/jetson2/Code/JetsonAI-2/cascade/eye.xml')
while True:
    
    ret, frame=cam.read()
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces=face_cascade.detectMultiScale(gray,1.3,5)
    for (x,y,w,h) in faces:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),2)
        Xcent=x+w/2
        Ycent=y+h/2
        errorPan=Xcent-dispW/2
        errorTilt=Ycent-dispH/2
        if abs(errorPan)>15:
            pan=pan-errorPan/50 
        if abs(errorTilt)>15:
            tilt=tilt-errorTilt/50
        if pan>180:
            pan=180
        if pan<0:
            pan=0
            print('Pan out of range')
        if tilt>180:
            tilt=0
        if tilt<0:
            tilt=0    
        kit.servo[0]=pan
        kit.servo[1]=tilt
        roi_gray=gray[y:y+h,x:x+w]
        roi_color=frame[y:y+h,x:x+w] 
        eyes=eye_cascaade.detectMultiScale(roi_gray)
        
        
        
        break
    cv2.imshow('nanoCam',frame)
    cv2.moveWindow('nanoCam',0,0)
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        break
cam.release()
cv2.destroyAllWindows()