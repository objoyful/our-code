import numpy as np
import cv2

##img1 = cv2.imread("plot1.png")
##img2 = cv2.imread("plot2.png")
fluf = cv2.imread("newfluf.png")
glasses = cv2.imread("sunglasses.png")
#cv2.imshow('Fluff Before', fluf)
#cv2.imshow('Glasses Before', glasses)

rows, cols, channels = glasses.shape
print('Rows', rows, 'Cols', cols, 'Channels', channels)#

y = 282 + rows
x = 585 + cols

roi = fluf[282:y, 585:x]
cv2.imshow('ROI', roi)#

grayglasses = cv2.cvtColor(glasses, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Glasses', grayglasses)

ret, mask = cv2.threshold(grayglasses, 150, 255, cv2.THRESH_BINARY_INV)
print('ret', ret)
cv2.imshow('Mask', mask)

mask_inv = cv2.bitwise_not(mask)
cv2.imshow('Mask Inv', mask_inv)


fluf_bg = cv2.bitwise_and(roi, roi, mask=mask_inv)
cv2.imwrite('coolfluf.jpg', fluf_bg)
cv2.imshow('Fluf Background', fluf_bg)
glasses_fg = cv2.bitwise_and(glasses, glasses, mask = mask)
cv2.imshow('Glasses Foreground', glasses_fg)

result = cv2.add(fluf_bg, glasses_fg)
cv2.imshow('Result', result)
fluf[282:y, 585:x] = result

cv2.imshow('Fluffy After', fluf)
cv2.waitKey(0)
cv2.destroyAllWindows()
