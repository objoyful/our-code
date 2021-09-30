import jetson.inference
import jetson.utils

net = jetson.inference.imageNet('googleNet')
cam = jetson.utils.gstCamera(1920, 1080, '/dev/video1')
disp = jetson.utils.glDisplay()

font = jetson.utils.cudaFont()

while disp.IsOpen():
    frame, width, height = cam.CaptureRGBA()
    
    classID, confident = net.Classify(frame, width, height)
    item = net.GetClassDesc(classID)

    font.OverlayText(frame, width, height, item, 5, 5, font.Magenta, font.Blue)
    
    disp.RenderOnce(frame, width, height)