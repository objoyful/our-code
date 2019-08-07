import cv2

book = cv2.imread('bookpage.jpg')
cv2.imshow('Original', book)

graybook = cv2.cvtColor(book, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', graybook)

ret, thresh = cv2.threshold(book, 7, 255, cv2.THRESH_BINARY)
cv2.imshow('Color Thresh', thresh)

graythresh = cv2.cvtColor(thresh, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Thresh', graythresh)

originaladaptive = cv2.adaptiveThreshold(graybook, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 115, 1)
cv2.imshow('Original Adaptive Thresh', originaladaptive)

adaptive = cv2.adaptiveThreshold(graybook, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 111, 3)
cv2.imshow('My Adaptive Thresh', adaptive)

cv2.waitKey(0)
cv2.destroyAllWindows()