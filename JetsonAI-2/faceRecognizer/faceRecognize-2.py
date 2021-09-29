import face_recognition
import cv2
print(cv2.__version__)
nancyFace=face_recognition.load_image_file('/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/known/Nancy Pelosi.jpg')
nancyEncode=face_recognition.face_encodings(nancyFace)[0]

donFace=face_recognition.load_image_file('/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/known/Donald Trump.jpg')
donEncode=face_recognition.face_encodings(donFace)[0]

penceFace=face_recognition.load_image_file('/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/known/Mike Pence.jpg')
penceEncode=face_recognition.face_encodings(penceFace)[0]

Encodings=[donEncode,nancyEncode]
names=['Donald Trump','Nancy Pelosi','Mike Pence']

font=cv2.FONT_HERSHEY_SIMPLEX
testImage=face_recognition.load_image_file('/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/unknown/u9.jpg')
facePositions=face_recognition.face_locations(testImage)
allEncodings=face_recognition.face_encodings(testImage,facePositions)

testImage=cv2.cvtColor(testImage,cv2.COLOR_RGB2BGR)

for (top,right,bottom,left), face_encoding in zip(facePositions,allEncodings):
    name='Unknown Person'
    matches=face_recognition.compare_faces(Encodings,face_encoding)
    if True in matches:
        first_match_index=matches.index(True)
        name=names[first_match_index]
    cv2.rectangle(testImage,(left,top),(right,bottom),(0,0,255),2)
    cv2.putText(testImage,name,(left,top-6),font,.75,(255,0,255),1)
cv2.imshow('myWindow',testImage)
cv2.moveWindow('myWindow',0,0)
if cv2.waitKey(0)==ord('q'):
    cv2.destroyAllWindows()