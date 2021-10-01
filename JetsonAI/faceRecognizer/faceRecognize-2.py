import face_recognition
import cv2
import face_recognition
print('CV2 Version:', cv2.__version__)

donFace = face_recognition.load_image_file('/home/jetson/Code/JetsonAI/faceRecognizer/demoImages/known/Donald Trump.jpg')
donEncode = face_recognition.face_encodings(donFace)[0]

nancyFace = face_recognition.load_image_file('/home/jetson/Code/JetsonAI/faceRecognizer/demoImages/known/Nancy Pelosi.jpg')
nancyEncode = face_recognition.face_encodings(nancyFace)[0]

penceFace = face_recognition.load_image_file('/home/jetson/Code/JetsonAI/faceRecognizer/demoImages/known/Mike Pence.jpg')
penceEncode = face_recognition.face_encodings(penceFace)[0]

Encodings = [donEncode, nancyEncode, penceEncode]
Names = ['Donald Trump', 'Nancy Pelosi', 'Mike Pence']

font = cv2.FONT_HERSHEY_SIMPLEX

testImage = face_recognition.load_image_file('/home/jetson/Code/JetsonAI/faceRecognizer/demoImages/unknown/u11.jpg')
facePositions = face_recognition.face_locations(testImage)
allEncodings = face_recognition.face_encodings(testImage, facePositions)

testImage = cv2.cvtColor(testImage, cv2.COLOR_RGB2BGR)

for (top, right, bottom, left), face_encoding in zip(facePositions, allEncodings):
    name = 'Unknown Person'
    matches = face_recognition.compare_faces(Encodings, face_encoding)

    if True in matches:
        first_match_index = matches.index(True)
        name = Names[first_match_index]
    
    cv2.rectangle(testImage, (left, top), (right, bottom), (255, 0, 0), 2)
    cv2.putText(testImage, name, (left, top - 6), font, 0.75, (255, 0, 255), 1)

cv2.imshow('My Window', testImage)
cv2.moveWindow('My Window', 0, 0)

if cv2.waitKey(0) == ord('q'):
    cv2.destroyAllWindows()