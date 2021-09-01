import cv2
print(cv2.__version__)
import numpy as np

def nothing(x):
    pass

cv2.namedWindow('Trackbars')
cv2.moveWindow('Trackbars',600,800)

cv2.createTrackbar('hueLower', 'Trackbars',50,179,nothing)
cv2.createTrackbar('hueHigher', 'Trackbars',100,179,nothing)

cv2.createTrackbar('hueLower2', 'Trackbars',50,179,nothing)
cv2.createTrackbar('hueHigher2', 'Trackbars',100,179,nothing)

cv2.createTrackbar('satLow', 'Trackbars',100,255,nothing)
cv2.createTrackbar('satHigh', 'Trackbars',255,255,nothing)

cv2.createTrackbar('valLow', 'Trackbars',100,255,nothing)
cv2.createTrackbar('valHigh', 'Trackbars',255,255,nothing)

dispW=640
dispH=480
flip=2
camSet='nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method='+str(flip)+' ! video/x-raw, width='+str(dispW)+', height='+str(dispH)+', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'
#cam=cv2.VideoCapture(camSet)
cam=cv2.VideoCapture(0)
while True:
    
    ret, frame=cam.read()
    #frame=cv2.imread('JetsonAI-2/smarties.png')
    cv2.imshow('nanoCam',frame)
    cv2.moveWindow('nanoCam',0,0)

    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    cv2.imshow('hsv',hsv)
    cv2.moveWindow('hsv',0,400)

    hueLow=cv2.getTrackbarPos('hueLower','Trackbars')
    hueUp=cv2.getTrackbarPos('hueHigher','Trackbars')

    hueLow2=cv2.getTrackbarPos('hueLower2','Trackbars')
    hueUp2=cv2.getTrackbarPos('hueHigher2','Trackbars')

    Ls=cv2.getTrackbarPos('satLow','Trackbars')
    Us=cv2.getTrackbarPos('satHigh','Trackbars')

    Lv=cv2.getTrackbarPos('valLow','Trackbars')
    Uv=cv2.getTrackbarPos('valHigh','Trackbars')

    l_b=np.array([hueLow,Ls,Lv])
    u_b=np.array([hueUp,Us,Uv])

    l_b2=np.array([hueLow2,Ls,Lv])
    u_b2=np.array([hueUp2,Us,Uv])

    FGmask=cv2.inRange(hsv,l_b,u_b)
    cv2.imshow('FGmask',FGmask)
    cv2.moveWindow('FGmask',400,0)

    FGmask2=cv2.inRange(hsv,l_b2,u_b2)
    FGmaskComp=(cv2.add(FGmask,FGmask2))
    cv2.imshow('FGmaskComp',FGmaskComp)
    cv2.moveWindow('FGMaskCOmp',850,0)

    FG=cv2.bitwise_and(frame,frame,mask=FGmask)
    cv2.imshow('FG',FG)
    cv2.moveWindow('FG',850,0)

    BGmask=cv2.bitwise_not(FGmaskComp)
    cv2.imshow('BGmask',BGmask)
    cv2.moveWindow('BGmask',1300,0)
    
    BG=cv2.cvtColor(BGmask,cv2.COLOR_GRAY2BGR)
    cv2.imshow('BG',BG)
    cv2.moveWindow('BG',1000,400)

    final=cv2.add(FG,BG)
    cv2.imshow('final',final)
    cv2.moveWindow('final',1450,400)
    
    if cv2.waitKey(1)==ord('q'):
        print('you broke it')
        break
cam.release()
cv2.destroyAllWindows()