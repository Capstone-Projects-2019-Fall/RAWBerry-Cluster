import numpy
import math
import cv2

"""
This script was originally used on different proprietary camera 
formats, such as Leica and DJI formats.
"""

def psnr(img1, img2):
    if (img1.shape[0] != img2.shape[0]) | (img1.shape[1] != img1.shape[1]):
        img2 = cv2.resize(img2, (img1.shape[1], img1.shape[0]))
    mse = numpy.mean((img1 - img2) ** 2)
    if mse == 0:
        return 100
    PIXEL_MAX = 255.0
    return 20 * math.log10(PIXEL_MAX / math.sqrt(mse))

# in_1: Leica
# in_2: DJI

id = 1
for x in range(1, 3):
    original = cv2.imread('in/in_' + "{}".format(id) + '.dng')
    compressed = cv2.imread('out/in_' + "{}".format(id) + '.dng', 1)
    id += 1

    print(psnr(original, compressed))

