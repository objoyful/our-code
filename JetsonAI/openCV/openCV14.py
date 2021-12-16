import cv2

def nothing(x):
    pass

cv2.namedWindow('Blended')
cv2.createTrackbar('Blend Value', 'Blended', 50, 100, nothing)

dispW = 320 * 2
dispH = 240 * 2

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = webCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

cvLogo = cv2.imread('JetsonAI/cv.jpg')
cvLogo = cv2.resize(cvLogo, (w, h))

cvLogoGray = cv2.cvtColor(cvLogo, cv2.COLOR_BGR2GRAY)
cv2.imshow('CV Logo Gray', cvLogoGray)


_, BGMask = cv2.threshold(cvLogoGray, 225, 255, cv2.THRESH_BINARY)
cv2.imshow('BG Mask', BGMask)


FGMask = cv2.bitwise_not(BGMask)
cv2.imshow('FG Mask', FGMask)


FG = cv2.bitwise_and(cvLogo, cvLogo, mask = FGMask)
cv2.imshow('FG', FG)


while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    BG = cv2.bitwise_and(frame, frame, mask = BGMask)
    cv2.imshow('BG', BG)
    cv2.moveWindow('BG', w + 100, 100)

    compImage = cv2.add(BG, FG)
    cv2.imshow('Comp. Image', compImage)
    cv2.moveWindow('Comp. Image', 2 * w, 100)

    BV1 = cv2.getTrackbarPos('Blend Value', 'Blended') / 100
    BV2 = 1 - BV1

    Blended = cv2.addWeighted(frame, BV1, cvLogo, BV2, 0)
    cv2.imshow('Blended', Blended)
    cv2.moveWindow('Blended', w + w2, h + 160)

    FG2 = cv2.bitwise_and(Blended, Blended, mask=FGMask)
    cv2.imshow('FG 2', FG2)
    cv2.moveWindow('FG 2', w + w2, 100)

    compFinal = cv2.add(BG, FG2)
    cv2.imshow('Comp. Final', compFinal)
    cv2.moveWindow('Comp. Final', 2 * w, h + 160)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 100)

    cv2.moveWindow('CV Logo Gray', 0, h + 160)
    cv2.moveWindow('BG Mask', w2 + 80, 100)
    cv2.moveWindow('FG Mask', w2 + 80, h + 160)
    cv2.moveWindow('FG', w + 100, h + 160)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()