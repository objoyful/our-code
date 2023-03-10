import cv2

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

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break
    
    roi = frame[200:600, 500:800].copy()
    roiGray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
    roiGray = cv2.cvtColor(roiGray, cv2.COLOR_GRAY2BGR)

    frame[200:600, 500:800] = roiGray[:]
    
    cv2.imshow('ROI', roi)
    cv2.moveWindow('ROI', w + 80, 0)

    cv2.imshow('ROI Gray', roiGray)
    cv2.moveWindow('ROI Gray', w + 80, 400)

    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()