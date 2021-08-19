import cv2
print(cv2.__version__)
dispW=1280
dispH=960
flip=2
def nothing(x):
        pass
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
cv2.namedWindow('piCam')
cv2.createTrackbar('height','piCam',0,dispW,nothing)
cv2.createTrackbar('width','piCam',0,dispH,nothing)
cv2.createTrackbar('xVal','piCam',0,dispW,nothing)
cv2.createTrackbar('yVal','piCam',0,dispH,nothing)


while True:
    ret, frame=cam.read()
    xVal=cv2.getTrackbarPos('xVal','piCam')
    yVal=cv2.getTrackbarPos('yVal','piCam')
    width=cv2.getTrackbarPos('width','piCam')
    height=cv2.getTrackbarPos('height','piCam')
    cv2.rectangle(frame,(xVal,yVal),(xVal+width,yVal+height),(255,0,0),3)
    cv2.imshow('piCam',frame)
    if cv2.waitKey(1)==ord('q'):
        break
cam.release()
cv2.destroyAllWindows()