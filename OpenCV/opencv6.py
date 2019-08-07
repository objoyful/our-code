import cv2

book = cv2.imread('bookpage.jpg')
cv2.imshow('Original', book)

# Converting to gryscale.
graybook = cv2.cvtColor(book, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', graybook)

# Adding a standard binaty thresh to the color image.
ret, thresh = cv2.threshold(book, 7, 255, cv2.THRESH_BINARY)
print('Ret', ret)
cv2.imshow('Color Thresh', thresh)

# Converting the thresh above to grayscale.
graythresh = cv2.cvtColor(thresh, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Thresh', graythresh)

# Adding a Guassian thresh. The last 2 numbers are the most important.
originaladaptive = cv2.adaptiveThreshold(graybook, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 115, 1)
cv2.imshow('Original Adaptive Thresh', originaladaptive)

# The one above is the one from the video. I changed it a little bit and made it better.
adaptive = cv2.adaptiveThreshold(graybook, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 111, 3)
cv2.imshow('My Adaptive Thresh', adaptive)

# This is an otsu thresh which has a fixed thresh value which you can't change.
otsu_ret, otsu = cv2.threshold(graybook, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
print('Otsu Ret', otsu_ret)
cv2.imshow('Otsu Thresh', otsu)

cv2.waitKey(0)
cv2.destroyAllWindows()