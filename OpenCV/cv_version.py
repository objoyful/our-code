try:
    import cv2
except ModuleNotFoundError:
    print("It looks like you do not have OpenCV-Python installed!")

print("Your version of OpenCV-Python is", cv2.__version__)