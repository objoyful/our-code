import cv2

dispW = 320 * 2
dispH = 240 * 2

smallW = 320 * 1
smallH = 240 * 1

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)
webCam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
webCam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

cam = webCam

while True:
    ret, frame = cam.read()
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 2 * smallW + 120, 0)

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    frameSmall = cv2.resize(frame, (320, 240))
    graySmall = cv2.resize(gray, (320, 240))

    cv2.moveWindow('Gray', 0, smallH + 60)
    cv2.moveWindow('Camera Small', 0, 0)

    cv2.imshow('Gray', graySmall)
    cv2.imshow('Camera Small', frameSmall)

    cv2.moveWindow('Gray 2', smallW + 80, smallH + 60)
    cv2.moveWindow('Camera 2', smallW + 80, 0)

    cv2.imshow('Gray 2', graySmall)
    cv2.imshow('Camera 2', frameSmall)


    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()