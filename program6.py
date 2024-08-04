Write a Program to read a digital image. Split and display image into 4 quadrants, up, down, right and left.

pip install opencv-python


import cv2
import matplotlib.pyplot as plt

image = cv2.imread('apple.jpg')
image_mat = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
ht, wd, c = image.shape

midy = ht//2
midx = wd//2

tl = image_mat[:midy, :midx]
tr = image_mat[:midy, midx: ]
bl = image_mat[midy: , :midx]
br = image_mat[midy: , midx: ]


fig, axs = plt.subplots(2,2)
l_title = ["Top Left", "Top Right", "Bottom Left", "Bottom Right"]
l_var = [tl, tr, bl, br]

k = 0
for i in range(2):
    for j in range(2):
        axs[i, j].imshow(l_var[k])
        axs[i, j].set_title(l_title[k])
        axs[i, j].axis("off")
        k +=  1  

plt.axis("off")
plt.show()
