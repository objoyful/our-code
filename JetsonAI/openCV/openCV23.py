import cv2
from adafruit_servokit import ServoKit
print(cv2.__version__)

dispW = 320 * 2
dispH = 240 * 2

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = webCam

cam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

kit = ServoKit(channels = 16)

pan = 90
tilt = 90

kit.servo[0].angle = pan
kit.servo[1].angle = tilt

face_cascade = cv2.CascadeClassifier('/home/jetson/Code/JetsonAI/cascade/face.xml')
eye_cascade = cv2.CascadeClassifier('/home/jetson/Code/JetsonAI/cascade/eye.xml')

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    for (x, y, w, h) in faces:
        Xcenter = x + w / 2
        Ycenter = y + h / 2

        errorPan = Xcenter - dispW / 2
        errorTilt = Ycenter - dispH / 2

        if abs(errorPan) > 15:
            pan = pan - errorPan / 50

        if abs(errorTilt) > 15:
            tilt = tilt + errorTilt / 50

        if pan > 180:
            pan = 180
            print("Pan out of range")

        if pan < 0:
            pan = 0
            print("Pan out of range")

        if tilt > 180:
            tilt = 180
            print("Tilt out of range")

        if tilt < 0:
            tilt = 0
            print("Tilt out of range")

        kit.servo[0].angle = pan
        kit.servo[1].angle = tilt

        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 3)
        
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = frame[y:y + h, x:x + w]
        
        eyes = eye_cascade.detectMultiScale(roi_gray)

        for (xEye, yEye, wEye, hEye) in eyes:
            cv2.rectangle(roi_color, (xEye, yEye), (xEye + wEye, yEye + hEye), (255, 255, 255), 3)

        break

    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()