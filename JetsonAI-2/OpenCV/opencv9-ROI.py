import cv2
print(cv2.__version__)
dispW=640
dispH=460
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
while True:
    ret, frame=cam.read()
    roi=frame[50:250,200:400].copy()
    roiGray=cv2.cvtColor(roi,cv2.COLOR_BGR2GRAY)
    frame[50:250,200:400]=[255,255,255]
    roiGray=cv2.cvtColor(roiGray,cv2.COLOR_GRAY2BGR)
    cv2.imshow('ROI',roi)
    cv2.imshow('GRAY',roiGray)
    cv2.moveWindow('GRAY',640,200)
    cv2.moveWindow('ROI',640,0)
    cv2.imshow('nanoCam',frame)
    if cv2.waitKey(1)==ord('q'):
        break
cam.release()
cv2.destroyAllWindows()