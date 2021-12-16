import cv2
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

eye_cascade = cv2.CascadeClassifier('/home/jetson/Code/JetsonAI/cascade/eye.xml')
face_cascade = cv2.CascadeClassifier('/home/jetson/Code/JetsonAI/cascade/face.xml')

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)

        roi_gray = gray[y:y + h, x:x + w]
        roi_color = frame[y:y + h, x:x + w]

        eyes = eye_cascade.detectMultiScale(roi_gray, 1.3, 5)

        for (xEye, yEye, wEye, hEye) in eyes:
            #cv2.rectangle(roi_color, (xEye, yEye), (xEye + wEye, yEye + hEye), (255, 255, 255), 2)
            cv2.circle(roi_color, (int(xEye + wEye / 2), int(yEye + hEye / 2)), 8, (255, 255, 255), -1)
            cv2.circle(roi_color, (int(xEye + wEye / 2), int(yEye + hEye / 2)), 4, (0, 0, 0), -1)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()