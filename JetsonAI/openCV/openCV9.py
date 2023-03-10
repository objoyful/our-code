import cv2

dispW = 320 * 2
dispH = 240 * 2

flip = 4

def nothing(x):
    pass

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = piCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

cv2.namedWindow('Camera')
cv2.createTrackbar('xVal', 'Camera', 0, w, nothing)
cv2.createTrackbar('yVal', 'Camera', 0, h, nothing)
cv2.createTrackbar('width', 'Camera', 0, w, nothing)
cv2.createTrackbar('height', 'Camera', 0, h, nothing)

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break
    
    xVal = cv2.getTrackbarPos('xVal', 'Camera')
    yVal = cv2.getTrackbarPos('yVal', 'Camera')
    width = cv2.getTrackbarPos('width', 'Camera')
    height = cv2.getTrackbarPos('height', 'Camera')

    cv2.rectangle(frame, (xVal, yVal), (xVal + width, yVal + height), (255, 0, 0), 3)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()