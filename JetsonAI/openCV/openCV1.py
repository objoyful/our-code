import cv2

dispW = 320 * 4
dispH = 240 * 4

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

dualCams = True
singleCam = webCam

while True:
    if dualCams:
        piRet, piFrame = piCam.read()
        webRet, webFrame = webCam.read()

        cv2.imshow('Pi Cam', piFrame)
        cv2.imshow('Web Cam', webFrame)
    else:
        singleCamRet, singleCamFrame = singleCam.read()

        cv2.imshow('Camera', singleCamFrame)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()