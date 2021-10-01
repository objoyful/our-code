import jetson.inference
import jetson.utils


# v4l2-ctl -d /dev/video1 --list-formats-ext
net = jetson.inference.detectNet('ssd-mobilenet-v2', threshold = 0.5)
cam = jetson.utils.gstCamera(640, 480, '/dev/video1')