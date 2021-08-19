import cv2
print(cv2.__version__)
def click(event,x,y,flags,params):
    if event==cv2.EVENT_LBUTTONDOWN:
        print('Mouse Event Was:', event)
        print(x,',',y)
dispW=1280
dispH=960
flip=2
cv2.setMouseCallback('nanocam',click)
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
while True:
    ret, frame=cam.read()
    cv2.imshow('nanoCam',frame)
    if cv2.waitKey(1)==ord('q'):
        break
cam.release()
cv2.destroyAllWindows()