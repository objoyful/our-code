import face_recognition
import cv2
import os
import pickle

from face_recognition.api import face_encodings

print(cv2.__version__)

dispW = 640
dispH = 480

font = cv2.FONT_HERSHEY_SIMPLEX

Encodings = []
Names = []

with open('JetsonAI/faceRecognizer/train.pkl', 'rb') as f:
    Names = pickle.load(f)
    Encodings = pickle.load(f)

cam = cv2.VideoCapture('/dev/video1')

cam.set(cv2.CAP_PROP_FRAME_WIDTH, dispW)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dispH)

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction.")
        break

    frameSmall = cv2.resize(frame, (0, 0), fx=0.33, fy=0.33)

    frameRGB = cv2.cvtColor(frameSmall, cv2.COLOR_BGR2RGB)

    facePositions = face_recognition.face_locations(frameRGB, model = 'hog')
    allEncodings = face_recognition.face_encodings(frameRGB, facePositions)


    for (top, right, bottom, left), faceEncoding in zip(facePositions, allEncodings):
        name = 'Unknown Person'

        matches = face_recognition.compare_faces(Encodings, faceEncoding)
        if True in matches:
            first_match_index = matches.index(True)
            name = Names[first_match_index]

        top = top *3
        right = right * 3
        bottom = bottom * 3
        left = left * 3

        cv2.rectangle(frame, (left, top), (right, bottom), (255, 0, 0), 3)
        cv2.putText(frame, name, (left, top - 6), font, 0.75, (0, 255, 255), 2)

    cv2.imshow('Frame', frame)
    cv2.moveWindow('Frame', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()