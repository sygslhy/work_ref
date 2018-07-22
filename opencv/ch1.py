import cv2

# open image
img = cv2.imread("./ukbench00000.jpg")
cv2.imshow("Image", img)
cv2.waitKey(0) 
'''
# save other format
cv2.imwrite("./res.png", img)

# convert to grey
greyimg = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow("Grey Image", greyimg)
cv2.waitKey(0)

# generate thumbnail
thumb = cv2.resize(img,(32,32))
cv2.imshow("thumb", thumb)
cv2.waitKey(0)

# histogram
hist = cv2.calcHist([greyimg], [0], None, [256], [0, 256])
print hist

# crop
cropped = img[70:170, 440:540]
cv2.imshow("cropped", cropped)
cv2.waitKey(0)
'''
# rotation
(rows, cols) = img.shape[:2]
center = (rows/2, cols/2)
M = cv2.getRotationMatrix2D(center, 90, 1.0)
res = cv2.warpAffine(img,M,(rows,cols))
cv2.imshow("ratation", res)
cv2.waitKey(0)



