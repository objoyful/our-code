import cv2
print(cv2.__version__)
dispW=640
dispH=480
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)

PL=cv2.imread('JetsonAI-2/pl.jpg')
PL=cv2.resize(PL,(75,75))
cv2.imshow('python logo',PL)
cv2.moveWindow('python logo',720,0)

PLGray=cv2.cvtColor(PL,cv2.COLOR_BGR2GRAY)
cv2.imshow('LGGray',PLGray)
cv2.moveWindow('LGGray',640,0)

_,BGMask=cv2.threshold(PLGray,245,255,cv2.THRESH_BINARY)
cv2.imshow('mask',BGMask)
cv2.moveWindow('mask',800,0)

FGMask=cv2.bitwise_not(BGMask)
cv2.imshow('FGMask',FGMask)
cv2.moveWindow('FGMask',880,0)

FG=cv2.bitwise_and(PL,PL,mask=FGMask)
cv2.imshow('FG',FG)
cv2.moveWindow('FG',960,0)

BW=75
BH=75
Xpos=10
Ypos=10
dX=1
dY=1

while True:
    
    ret, frame=cam.read()
    
    ROI=frame[Ypos:Ypos+BH,Xpos:Xpos+BW]
    ROIBG=cv2.bitwise_and(ROI,ROI,mask=BGMask)
    cv2.imshow('ROIBG',ROIBG)
    cv2.moveWindow('ROIBG',1040,0)
    
    ROInew=cv2.add(FG,ROIBG)
    cv2.imshow('ROInew',ROInew)
    cv2.moveWindow('ROInew',1120,0)
    frame[Ypos:Ypos+BH,Xpos:Xpos+BW]=ROInew

    Xpos=Xpos+dX
    Ypos=Ypos+dY

    if Xpos<=0 or Xpos+BW>=dispW:
        dX=dX*(-1)
        print('boing')   
    if Ypos<=0 or Ypos+BH>=dispH:
        dY=dY*(-1)
        print('boing')

    cv2.imshow('nanoCam',frame)
    cv2.moveWindow('nanoCam',0,0)
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        break
cam.release()
cv2.destroyAllWindows()