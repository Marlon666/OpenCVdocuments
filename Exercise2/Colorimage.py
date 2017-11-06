import cv2
import numpy as np

img = cv2.imread("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/Lenna.png")
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Original.png", img)

#RGB
b,g,r = cv2.split(img)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Blue.png",b)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Green.png",g)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Red.png",r)

#ycbcr
ycbcr_image = cv2.cvtColor(img,cv2.COLOR_BGR2YCR_CB)
y,cb,cr = cv2.split(ycbcr_image)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/y.png",y)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/cb.png",cb)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/cr.png",cr)

#hsv
hsv_image = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
h,s,v = cv2.split(hsv_image)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Hue.png",h)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Saturation.png",s)
cv2.imwrite("/Users/limuzi/Documents/codes/EC601_OpenCV_excercise/Excercise2/output/Value.png",v)

