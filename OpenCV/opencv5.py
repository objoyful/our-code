import numpy as np
import cv2

##img1 = cv2.imread("plot1.png")
##img2 = cv2.imread("plot2.png")
fluf = cv2.imread("newfluf.png")
glasses = cv2.imread("sunglasses.png")

rows, cols, channels = glasses.shape
print('Rows', rows, 'Cols', cols, 'Channels', channels)#

roi = fluf[282:(283 + rows), 585:(585 + cols)]
cv2.imshow('ROI', roi)#

grayglasses = cv2.cvtColor(glasses, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Glasses', grayglasses)

ret, mask = cv2.threshold(grayglasses, 150, 255, cv2.THRESH_BINARY_INV)
print('ret', ret)
cv2.imshow('Mask', mask)

mask_inv = cv2.bitwise_not(mask)
cv2.imshow('Mask Inv', mask_inv)


newfluf_bg = cv2.bitwise_and(roi,roi,mask = mask_inv)
#cv2.imshow('Fluf Background', fluf_bg)











cv2.waitKey(0)
cv2.destroyAllWindows()
