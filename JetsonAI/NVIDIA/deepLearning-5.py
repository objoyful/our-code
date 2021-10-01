import jetson.inference
import jetson.utils
import time
import cv2
import numpy as np

timeStamp = time.time()
fpsFiltered = 0

net = jetson.inference.detectNet('ssd-mobilenet-v2', threshold = 0.5)

dispW = 1920
dispH = 1080

# cam = jetson.utils.gstCamera(dispW, dispH, '/dev/video1')
cam = cv2.VideoCapture('/dev/video1')

cam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

# display = jetson.utils.glDisplay()

font = cv2.FONT_HERSHEY_SIMPLEX

# while display.IsOpen():
while True:
    # img, width, height = cam.CaptureRGBA()
    ret, img = cam.read()

    if not ret:
        print("Camera malfunction")

    width = img.shape[1]
    height = img.shape[0]

    frame = cv2.cvtColor(img, cv2.COLOR_BGR2RGBA).astype(np.float32)
    frame = jetson.utils.cudaFromNumpy(frame)

    detections = net.Detect(frame, width, height)
    for detect in detections:
        ID = detect.ClassID
        
        top = detect.Top
        left = detect.Left
        bottom = detect.Bottom
        right = detect.Right

        item = net.GetClassDesc(ID)
        print(item, top, left, bottom, right)

    dt = time.time() - timeStamp
    timeStamp = time.time()

    fps = 1 / dt
    fpsFiltered = fpsFiltered * 0.9 + fps * 0.1

    # display.RenderOnce(img, width, height)

    cv2.putText(img, str(round(fpsFiltered, 1)) + ' FPS', (0, 40), font, 1, (0, 0, 255), 3)

    cv2.imshow('Detect Cam', img)
    cv2.moveWindow('Detect Cam', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break
cam.release()
cv2.destroyAllWindows