import cv2

dispW = 320 * 2
dispH = 240 * 2

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

cam = piCam
cam2 = webCam

while True:
    ret, frame = cam.read()
    ret, frame2 = cam2.read()

    name = 'Pi Camera'
    cv2.imshow(name, frame)
    cv2.moveWindow(name, 0, 0)
    
    name = 'Web Camera'
    cv2.imshow(name, frame2)
    cv2.moveWindow(name, dispW + 80, 0)

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray2 = cv2.cvtColor(frame2, cv2.COLOR_BGR2GRAY)

    name = 'Gray Pi Camera'
    cv2.imshow(name, gray)
    cv2.moveWindow(name, 0, dispH + 60)

    name = 'Gray Webcam'
    cv2.imshow(name, gray2)
    cv2.moveWindow(name, dispW + 80, dispH + 60)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()