from threading import Thread
import time

def BigBox(color, l, w):
    while True:
        print(color, 'Box is Open of length', l, 'and width', w)
        time.sleep(5)
        
        print(color, 'Box is Closed of length', l, 'and width', w)
        time.sleep(5)

def SmallBox(color, l, w):
    while True:
        print(color, 'Box is Open of length', l, 'and width', w)
        time.sleep(1)

        print(color, 'Box is Closed of length', l, 'and width', w)
        time.sleep(1)

c = 'red'
x = 5
y = 6
bigBoxThread = Thread(target = BigBox, args = (c, x, y))

c = 'blue'
x = 4
y = 6
smallBoxThread = Thread(target = SmallBox, args = (c, x, y))

bigBoxThread.daemon = True
smallBoxThread.daemon = True

bigBoxThread.start()
smallBoxThread.start()

while True:
    pass