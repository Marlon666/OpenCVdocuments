# OpenCVdocuments

It's a exercise after reading the OpenCV documents and walktrough

## Exercise 1
Matrix elements are stored row by row. Element (i, j) (i - 0-based row index, j - 0-based column index) of a matrix can be retrieved or modified using CV_MAT_ELEM macro:

uchar pixval = CV_MAT_ELEM(grayimg, uchar, i, j)
CV_MAT_ELEM(cameraMatrix, float, 0, 2) = image.width*0.5f;
To access multiple-channel matrices, you can use CV_MAT_ELEM(matrix, type, i, j*nchannels + channel_idx).

## Exercise 2
#1.The outputs are 10 images:

The first image is the orginial image.

The 2nd to the 4th images show the intensity of the colors, red, green and blue, in the orginal image.

The 5th image shows the luma component of the image.

The 6th and 7th images show The blue-difference and red-difference chroma components of the image.

The 8th image shows the degree to which a stimulus can be described as similar to or different from stimuli

The 9th image shows the saturation of a color which is determined by a combination of light intensity and how much it is distributed across the spectrum of different wavelengths.

The 10th images shows the brightness of the image.

#2.The value of pixel at (20,25) of Lenna image

('RGB [20,25] : ', array([106, 122, 225], dtype=uint8))
('YCbCr [20,25] : ', array([151, 181, 103], dtype=uint8))
('HSV [20,25] : ', array([  4, 135, 225], dtype=uint8))
The ranges of pixel values:

RGB: 
R : 0 ~ 255
G : 0 ~ 255
B : 0 ~ 255
YCbCr with Sub sampling ratio 4:2:0
Luma Y : 16 ~ 235
Chorma Cb : 16 ~ 240
Chorma Cr : 16 ~ 240

YCbCr with Sub sampling ratio 4:4:4
Luma Y : 0 ~ 255
Chorma Cb : 0 ~ 255
Chorma Cr : 0 ~ 255
HSV:
H : 0 ~ 180
S : 0 ~ 255
V : 0 ~ 255

## Exercise 3
As the values increasing, there are more noise created. As the kernels sizes increase, the resulting image gets more blur. I use the Gaussian Noise with mean = 0, sigma = 20 and Salt-and-pepper Noise with pa = 0.01, pb = 0.01 in the kernel changing cases.
The results shows that for Gaussian Noise, Gaussian Filter works better, and for Salt-and-Pepper Noise, Median filter works better.

## Exercise 4
#1.In adaptive threshold, the algorithm calculate the threshold for a small regions of the image. So we get different thresholds for different regions of the same image and it gives us better results for images with varying illumination.

The band threshold take the upper band and lower band, which only shows limited range of color scalar of the images.

The binary threshold only shows black and white by deviding equally the range of colors.

The semi threshold takes the extreme value from the high value and low value.

#2.The binary threshold takes one threshold value for the whole image and resulted in a black and white only. It may not suitable for all kind of image/condition. For example, if an image are concentrated on only certain range of gray scale, then it will show nothing after the binary threshold.

#3.Adaptive binarization can be divided into three categories:

Global method: with this method first of the background of the image is estimated; after that a normalized image is generated with the help of the background information. Then global binarization method is employed.

Patch-based method: as the name indicates, patch-based method will perform binarization patch by patch. At each patch, a binarization is estimated with a global binarization method. After that, some post-processing is performed to make sue that binarization threshold in neighboring patches has smooth transition.

Moving-window method: with this method, binarization is done pixel by pixel. A moving window is set up to calculate the pixel statistics within the window, and based on the statistics the threshold for the central pixel within the window is calculated.

