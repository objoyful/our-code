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

print(w / h)

i = 0
maxNum = False
while True:
    print(i)
    ret, frame = cam.read()
    
    frame = cv2.circle(frame, (w2, h2), 50, (255, 0, 255), -1)

    fnt = cv2.FONT_HERSHEY_DUPLEX
    frame = cv2.putText(frame, 'My First Text', (600, 500), fnt, 1, (255, 0, 150), 2)
    
    frame = cv2.line(frame, (10, 10), (1200, 700), (0, 0, 0), 7)
    frame = cv2.arrowedLine(frame, (10, 700), (1200, 110), (255, 255, 255), 3)

    frame = cv2.rectangle(frame, (0 + (16 * i), h - (10 * i)), (200 + (16 * i), (h - 100) - (10 * i)), (0, 255, 0), -1)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break
    
    if 200 + (16 * i) >= w - 16:
        maxNum = True
    
    if 16 * i <= 16:
        maxNum = False
    
    if maxNum:
        i = i - 2
    else:
        i = i + 2

cam.release()
cv2.destroyAllWindows()