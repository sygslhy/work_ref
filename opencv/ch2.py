import numpy as np
import cv2

#point operation
img = cv2.imread("./ukbench00000.jpg")
print img.shape
print img.ndim
print img.dtype
print img.itemsize


b, g, r = cv2.split(img)
cv2.imshow("Image B", b)
cv2.waitKey(0)

print b.ndim
print b.dtype
