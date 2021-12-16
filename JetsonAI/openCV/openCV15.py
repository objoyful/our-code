import cv2

dispW = 320 * 2
dispH = 240 * 2

flip = 4

BW = 75
BH = 75

Xpos = 10
Ypos = 10

dX = 5
dY = 5

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = webCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

PL = cv2.imread('JetsonAI/pl.jpg')

PL = cv2.resize(PL, (BW, BH))
cv2.imshow('Logo', PL)

PLG = cv2.cvtColor(PL, cv2.COLOR_BGR2GRAY)
cv2.imshow('Logo Gray', PLG)

_, BGMask = cv2.threshold(PLG, 245, 255, cv2.THRESH_BINARY)
cv2.imshow('BG Mask', BGMask)

FGMask = cv2.bitwise_not(BGMask)
cv2.imshow('FG Mask', FGMask)

FG = cv2.bitwise_and(PL, PL, mask = FGMask)
cv2.imshow('FG', FG)

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    ROI = frame[Ypos:Ypos + BH, Xpos:Xpos + BW]
    cv2.imshow('ROI', ROI)
    cv2.moveWindow('ROI', w + 580, 0)

    BG = cv2.bitwise_and(ROI, ROI, mask = BGMask)
    cv2.imshow('BG', BG)
    cv2.moveWindow('BG', w + 680, 0)

    final = cv2.add(BG, FG)
    cv2.imshow('Final', final)
    cv2.moveWindow('Final', w + 780, 0)

    frame[Ypos:Ypos + BH, Xpos:Xpos + BW] = final
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    cv2.moveWindow('Logo', w + 80, 0)
    cv2.moveWindow('Logo Gray', w + 180, 0)
    cv2.moveWindow('BG Mask', w + 280, 0)
    cv2.moveWindow('FG Mask', w + 380, 0)
    cv2.moveWindow('FG', w + 480, 0)

    Xpos = Xpos + dX
    Ypos = Ypos + dY

    if Xpos >= w - BW or Xpos <= 0:
        dX = dX * (-1)

    if Ypos >= h - BH or Ypos <= 0:
        dY = dY * (-1)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()