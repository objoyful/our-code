import os
from gtts import gTTS

myText = 'testing text to speech'

myOutput = gTTS(text=myText, lang='en', slow=False)
myOutput.save('JetsonAI/GPIO/talk.mp3')
os.system('mpg123 JetsonAI/GPIO/talk.mp3')