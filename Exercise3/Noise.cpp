
import cv2
import numpy as np

def Add_salt_pepper_Noise(srcArr,pa,pb):
	N_SP_img = srcArr
	shape0 = srcArr.shape[0]-1
	shape1 = srcArr.shape[1]-1
	amount1 = int(pa*shape0*shape1)
	amount2 = int(pb*shape0*shape1)

	for i in range(amount1):
		x_random=np.random.random_integers(0,shape0)
		y_random=np.random.random_integers(0,shape1)
		N_SP_img[x_random,y_random]=0

	for i in range(amount2):
		x_random=np.random.random_integers(0,shape0)
		y_random=np.random.random_integers(0,shape1)
		N_SP_img[x_random,y_random]=255         
	return N_SP_img 

def Add_GNoise(srcArr,mean,sigma):
	N_G_img = srcArr.copy()
	cv2.randn(N_G_img,mean,sigma)
	cv2.add(srcArr,N_G_img,N_G_img)
	return N_G_img



def main():
	srcArr = cv2.imread("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/cameraman.png")
	img = cv2.cvtColor(srcArr,cv2.COLOR_RGB2GRAY)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/Orignial.png",img)
	
# Gaussain noise
	mean = 0
	sigma = 20
	gaussian_noise = Add_GNoise(img,mean,sigma)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/Gaussian_noise.png", gaussian_noise)

	# Box filter
	noise_dst = gaussian_noise.copy()
	gn_Blur = cv2.blur(noise_dst,(7,7))
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/GN_BoxFilter.png", gn_Blur)

	# Gaussain filter
	noise_dst1 = gaussian_noise.copy()
	gn_GaussianBlur = cv2.GaussianBlur(noise_dst1,(7,7),1.5)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/GN_GaussianFilter.png", gn_GaussianBlur)

	# Median filter
	noise_dst2 = gaussian_noise.copy()
	gn_MedianFilter = cv2.medianBlur(noise_dst2,7)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/GN_MedianFilter.png", gn_MedianFilter)

# Sault and Pepper noise
	pa = 0.01
	pb = 0.01
	sp_noise = Add_salt_pepper_Noise(img,pa,pb)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/Slat_and_Pepper_Noise.png", sp_noise)

	# Box filter
	noise_dst = sp_noise.copy()
	sp_Blur = cv2.blur(noise_dst,(7,7))
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/SP_BoxFilter.png", sp_Blur)

	# Gaussain filter
	noise_dst1 = sp_noise.copy()
	sp_GaussianBlur = cv2.GaussianBlur(noise_dst1,(7,7),1.5)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/SP_GaussianFilter.png", sp_GaussianBlur)

	# Median filter
	noise_dst2 = sp_noise.copy()
	sp_MedianFilter = cv2.medianBlur(noise_dst2,7)
	cv2.imwrite("/Users/bubble/Documents/GitHub/EC601_OpenCV_excercise/Excercise3/output/SP_MedianFilter.png", sp_MedianFilter)



if __name__=="__main__":
	main()

