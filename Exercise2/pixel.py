import cv2
import numpy as np

img = cv2.imread("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/Lenna.png")

#RGB
RGB = img[20,25]

#ycbcr
ycbcr_image = cv2.cvtColor(img,cv2.COLOR_BGR2YCR_CB)
ycbcr = ycbcr_image[20,25]
#hsv
hsv_image = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
hsv = hsv_image[20,25]

print("RGB [20,25] : " , RGB)
print("YCbCr [20,25] : " , ycbcr)
print("HSV [20,25] : " , hsv)
