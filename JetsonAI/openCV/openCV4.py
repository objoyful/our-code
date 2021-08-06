import cv2

dispW = 320 * 3
dispH = 240 * 3

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)
video = cv2.VideoCapture('JetsonAI/Videos/myCam.avi')

# Web cam or pi cam setting
cam = video

camWidth = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
camHeight = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))
camFPS = int(cam.get(cv2.CAP_PROP_FPS))

print(f"Resolution: {camWidth} x {camHeight} at {camFPS} FPS")
#outVid = cv2.VideoWriter('JetsonAI/Videos/myCam.avi', cv2.VideoWriter_fourcc(*'XVID'), camFPS, (camWidth, camHeight))

while True:
    ret, frame = cam.read()
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    #outVid.write(frame)

    if cv2.waitKey(int(1000 / camFPS)) == ord('q'):
        break

cam.release()
#outVid.release()
cv2.destroyAllWindows()