import cv2
print(cv2.__version__)
dispW=320 * 3
dispH=240 * 3
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
outVid=cv2.VideoWriter('JetsonAI-2/videos/mycam2.avi',cv2.VideoWriter_fourcc(*'XVID'),200,(dispW,dispH))
while True:
    ret, frame=cam.read()
    cv2.imshow('piCam',frame)
    cv2.moveWindow('piCam', 0,0)
    #outVid.write(frame)
    if cv2.waitKey(1)==ord('q'):
        break
cam.release()
outVid.release()
cv2.destroyAllWindows()