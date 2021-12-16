import cv2

x1 = 0
y1 = 0

x3 = 0
y3 = 0

goFlag = None
def mouse_click(event, x, y, flags, params):
    global x1, y1, x2, y2, x3, y3
    global goFlag

    if event == cv2.EVENT_LBUTTONDOWN:
        print('L Button Down:', event)
        
        x1 = x
        y1 = y

        goFlag = 0
    
    if event == cv2.EVENT_LBUTTONUP:
        print('L Button Up:', event)

        x2 = x
        y2 = y

        goFlag = 1

        xyString = '(' + str(x1) + ', ' + str(y1) + '), (' + str(x2) + ', ' + str(y2) + ')'
        print(xyString)

    x3 = x
    y3 = y

    locationString = '(' + str(x) + ', ' + str(y) + ')'
    print(locationString)


cv2.namedWindow('Camera')
cv2.setMouseCallback('Camera', mouse_click)

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

    if goFlag == 1:
        frame = cv2.rectangle(frame, (x1, y1), (x2, y2), (255, 0, 0), 3)
        
        roi = frame[y1:y2, x1:x2].copy()
        cv2.imshow('ROI', roi)
        cv2.moveWindow('ROI', w + 80, 0)

    if goFlag == 0:
        frame = cv2.rectangle(frame, (x1, y1), (x3, y3), (255, 0, 0), 3)

    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()