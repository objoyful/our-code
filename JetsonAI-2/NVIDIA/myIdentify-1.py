import jetson.inference
import jetson.utils

cam=jetson.utils.getCamera(1280,720,'dev/video0')
disp=jetson.utils.glDisplay()
font=jetson.utils.cudaFont()
net=jetson.inference.imageNet('googlenet')

while display.IsOpen():
    frame, width, height=cam.CaptureRGBA()
    classID, confidennet.Classify(frame, width, height)
    item=net.GetClassDesc(classID)
    font.OverlayText(frame, width, height, item, 5,5 font.Magenta, font.Blue)
    disp.RenderOnce(frame, width, height)