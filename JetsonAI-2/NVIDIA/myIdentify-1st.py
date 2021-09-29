import jetson.inference
import jetson.utils

net=jetson.inference.detectNet('ssd-mobilenet-v2',thresh=.5)
cam=jetson.utils.gstCamera(,"dev/video0")