import cv2
print(cv2.__version__)
def nothing():
    pass
cv2.namedWindow('Blended')
cv2.createTrackbar('BlendValue','Blended',50,100,nothing)

dispW=320
dispH=240
flip=2

camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)

dispwvar=int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
disphvar=int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

cvLogo=cv2.imread('JetsonAI-2/cv.jpg')
cvLogo=cv2.resize(cvLogo,(dispwvar,disphvar))

cvLogoGray=cv2.cvtColor(cvLogo,cv2.COLOR_BGR2GRAY)
cv2.imshow('cvLogoGray',cvLogoGray)
cv2.moveWindow('cvLogoGray',0,550)

_,BGMask=cv2.threshold(cvLogoGray,225,255,cv2.THRESH_BINARY)
cv2.imshow('BG Mask',BGMask)
cv2.moveWindow('BG Mask',640,0)

FGMask=cv2.bitwise_not(BGMask)
cv2.imshow('FGMask',FGMask)
cv2.moveWindow('FGMask',1275,0)

FG=cv2.bitwise_and(cvLogo,cvLogo,mask=FGMask)
cv2.imshow('FG',FG)
cv2.moveWindow('FG',1275,600)
while True:
    
    ret, frame=cam.read()
    
    BG=cv2.bitwise_and(frame,frame,mask=BGMask)
    cv2.imshow('BG',BG)
    cv2.moveWindow('BG',640,500)
    
    compImage=cv2.add(BG,FG)
    cv2.imshow('together',compImage)
    cv2.moveWindow('together',1272,500)
    
    BV1=cv2.getTrackbarPos('BlendValue','Blended')/100
    BV2=1-BV1

    Blended=cv2.addWeighted(frame,BV1,cvLogo,BV2,0)
    cv2.imshow('Blended',Blended)
    cv2.moveWindow('Blended',1275,0)

    FG2=cv2.bitwise_and(Blended,Blended,mask=FGMask)
    cv2.imshow('FG2',FG2)
    cv2.moveWindow('FG2',0,550)

    compFinal=cv2.add(BG,FG2)
    cv2.imshow('compFinal',compFinal)
    cv2.moveWindow('compFinal',0,0)
    
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        break
cam.release()
cv2.destroyAllWindows()