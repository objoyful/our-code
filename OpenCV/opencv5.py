import cv2

##img1 = cv2.imread("plot1.png")
##img2 = cv2.imread("plot2.png")
fluf = cv2.imread("newfluf.png")
glasses = cv2.imread("sunglasses.png")
#glasses = cv2.imread("newglasses.png")
#cv2.imshow('Fluff Before', fluf)
#cv2.imshow('Glasses Before', glasses)

# Gets the shape of the glasses.
rows, cols, channels = glasses.shape
print('Rows', rows, 'Cols', cols, 'Channels', channels)#

y = 282 + rows
x = 585 + cols

# Defines the region of image.
roi = fluf[282:y, 585:x]
cv2.imshow('ROI', roi)

# Convert the glasses to grayscale. Doesn't really do anything.
grayglasses = cv2.cvtColor(glasses, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Glasses', grayglasses)

# Threshold the glasses. Anything over 150 is black (inverse thresh) and anything under is black.
ret, mask = cv2.threshold(grayglasses, 150, 255, cv2.THRESH_BINARY_INV)
print('ret', ret)
cv2.imshow('Mask', mask)

# Inverse the threshold.
mask_inv = cv2.bitwise_not(mask)
cv2.imshow('Mask Inv', mask_inv)

# Replace the white background of mask inverse with fluf.
fluf_bg = cv2.bitwise_and(roi, roi, mask=mask_inv)
cv2.imwrite('coolfluf.jpg', fluf_bg)
cv2.imshow('Fluf Background', fluf_bg)

# Replace the white part of mask with the original glasses image. This should give us color (if we have any).
glasses_fg = cv2.bitwise_and(glasses, glasses, mask = mask)
cv2.imshow('Glasses Foreground', glasses_fg)

# Now we add the two.
result = fluf_bg + glasses_fg
cv2.imshow('Result', result)
# and set the roi to our result.
fluf[282:y, 585:x] = result

# ta da!
cv2.imshow('Fluffy After', fluf)
cv2.waitKey(0)
cv2.destroyAllWindows()