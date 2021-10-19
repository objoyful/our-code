from os import wait
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.OUT)

waitTime = 0.75
while True:
    try:
        GPIO.output(7, True)
        time.sleep(waitTime)
        
        waitTime = waitTime * 0.95

        GPIO.output(7, False)
        time.sleep(waitTime)

        waitTime = waitTime * 0.95

    except KeyboardInterrupt:
        break
GPIO.cleanup()
print("exited gracefully")