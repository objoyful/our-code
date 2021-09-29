import face_recognition
import cv2
import os
import pickle
print(cv2.__version__)
Encodings=[]
Names=[]
j=0

image_dir='/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/known'
for root, dirs, files in os.walk(image_dir):
    print(files)
    for file in files:
        path=os.path.join(root,file)
        print(path)
        name=os.path.splitext(file)[0]
        print(name)
        person=face_recognition.load_image_file(path)
        encoding=face_recognition.face_encodings(person)[0]
        Encodings.append(encoding)
        Names.append(name)
print(Names)

with open('train.pkl','wb') as f:
    pickle.dump(Names,f)
    pickle.dump(Encodings,f)
Encodings=[]
Names=[]
with open('train.pkl','rb') as f:
    Names=pickle.load(f)
    Encodings=pickle.load(f)

font=cv2.FONT_HERSHEY_SIMPLEX

image_dir='/home/jetson2/Code/JetsonAI-2/faceRecognizer/demoImages/unknown'
for root,dirs, files in os.walk(image_dir):
    for file in files:
        print(root)
        print(file)
        testImagePath=os.path.join(root,file)
        testImage=face_recognition.load_image_file(testImagePath)
        facePositions=face_recognition.face_locations(testImage)
        allEncodings=face_recognition.face_encodings(testImage,facePositions)
        testImage=cv2.cvtColor(testImage,cv2.COLOR_RGB2BGR)
 
        for (top,right,bottom,left),face_encoding in zip(facePositions,allEncodings):
            name='Unknown Person'
            matches=face_recognition.compare_faces(Encodings,face_encoding)
            if True in matches:
                first_match_index=matches.index(True)
                name=Names[first_match_index]
            cv2.rectangle(testImage,(left,top),(right,bottom),(0,0,255),2)
            cv2.putText(testImage,name,(left,top-6),font,.75,(0,255,255),2)
        cv2.imshow('Picture', testImage)
        cv2.moveWindow('Picture',0,0)
        if cv2.waitKey(0)==ord('q'):
            cv2.destroyAllWindows()