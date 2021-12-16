import os
import pyttsx3

engine = pyttsx3.init()

engine.setProperty('rate', 150)
engine.setProperty('voice', 'english+f4')

text = 'test test test'

engine.say(text)
engine.runAndWait()