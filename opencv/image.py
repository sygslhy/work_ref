import cv2
import numpy as np
import matplotlib.pyplot as plt
img = cv2.imread("./ukbench00000.jpg")
print img.shape[2] # channels
print img.shape[0:2] # dimensions
(b, g, r) = cv2.split(img)
#cv2.imshow("Blue", b)
#cv2.imshow("Green", g)
#cv2.imshow("Red", r)

# caculate and draw histogram
histb = cv2.calcHist([b], [0], None, [256], [0.0, 256.0])
#plt.hist(histb, bins=256, range=(0.0, 256.0))
#plt.title("B")
#plt.show()

grayimg = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
histY = cv2.calcHist([grayimg], [0], None, [256], [0.0, 256.0])
plt.title("Y")
plt.xlabel("pixel value")
plt.ylabel("pixel number")
plt.hist(histY, bins=64, range=(0.0, 256.0))
#plt.show()

res = np.uint8(np.clip(255-img, 0, 255))
#cv2.imshow("Image", res)
#cv2.waitKey(0)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
(h, s, v) = cv2.split(hsv)
#cv2.imshow("H", h)
#cv2.imshow("S", s)
#cv2.imshow("V", v)
#cv2.waitKey(0)

yuv = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)
(y, u, v) = cv2.split(yuv)
#cv2.imshow("Y", y)
#cv2.imshow("U", u)
#cv2.imshow("V", v)
#cv2.waitKey(0)

crop = img[100:400, 100:400]
#cv2.imshow("CROP", crop)
#cv2.waitKey(0)

#thm = cv2.resize(img, (1080, 720))
#cv2.imshow("Thumb", thm)
#cv2.waitKey(0)

#gamma correction
gamma_norm = np.power((img/255.0), 1/2.2)
gamma = np.uint8(np.clip(gamma_norm*255, 0, 255))
#cv2.imwrite("./gamma.png", gamma)
#cv2.imshow("Gamma=2.2", gamma)
#cv2.imshow("Image", img)
#cv2.waitKey(0)

#filter
"""
blur = cv2.blur(img,(5,5))
cv2.imshow("Blur", blur)
cv2.waitKey(0)


Gblur = cv2.GaussianBlur(img,(5,5),0)
cv2.imshow("GBlur", Gblur)
cv2.waitKey(0)

median = cv2.medianBlur(img,5)
cv2.imshow("Median", median)
cv2.waitKey(0)
"""

#shapen
kernel = np.array(
        [[-1, -1, -1],
         [-1, 8, -1],
         [-1, -1, -1]]
)

shapen = cv2.filter2D(img, -1, kernel)
#cv2.imshow("Shapen", shapen)
#cv2.waitKey(0)

#zoom
crop_zoom = img[200:300, 300:400]
resized = cv2.resize(crop_zoom, (640, 480), interpolation=cv2.INTER_CUBIC)
#cv2.imshow("Zoom", resized)
#cv2.waitKey(0)

#white balance
b_sc = 1.4
r_sc = 1.0
b_ch = np.uint8(np.clip(b*b_sc, 0, 255))
r_ch = np.uint8(np.clip(r*r_sc, 0, 255))
g_ch = g
merged = cv2.merge([b_ch,g_ch,r_ch])
#cv2.imshow("Origin", img)
#cv2.imshow("WB", merged)
#cv2.waitKey(0)

#histogram equalize
eq = cv2.equalizeHist(grayimg)
#cv2.imshow("Equlized", np.hstack([grayimg, eq]) )
#cv2.waitKey(0)

#image threshold
(ret, binary) = cv2.threshold(grayimg, 127, 255, cv2.THRESH_BINARY )
#cv2.imshow("Binnary", np.hstack([grayimg, binary]) )
#cv2.waitKey(0)


#fourrier transform
f = np.fft.fft2(grayimg)
fshift = np.fft.fftshift(f)
magnitude_spectrum = 20*np.log(np.abs(fshift))
"""
plt.subplot(121),plt.imshow(grayimg, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(magnitude_spectrum, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()
"""

#tone curve
tone = np.array(range(0,256))
tone_img = np.array(range(640*480)).reshape(480, 640)
print tone
print tone_img.shape
for i in range(grayimg.shape[0]):
	for j in range(grayimg.shape[1]):
		#print tone[grayimg[i][j]]
		tone_img[i][j] = tone[grayimg[i][j]]
print tone_img
cv2.imwrite("./ToneCurve.png", tone_img)



