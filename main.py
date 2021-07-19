import numpy as np
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import os
import logging
import asyncio
import random
from PIL import Image, ImageFilter
import time
from datetime import datetime


def filter_format(directory):
    images_directory = [directory]
    format_list = ['jpg', 'png']
    for root, dirs, files in os.walk(directory, topdown=False):
        for i in files:
            for j in format_list:
                if i[-len(j) - 1:] == "." + j:
                    # print("root :", root, "\ndirs : ", dirs, "\nfile : ", i)
                    # colorImage1 = Image.open(root+'\\'+i)
                    images_directory.append(root + '\\' + i)
    return images_directory

#
async def rotate_image(path, degree, dir1):
    # print(f"path: {path} : degree {degree}")
    print(f"rotate : {dir1[-5:]}  started -> ", datetime.now())
    image_set = Image.open(path)
    r_image = image_set.rotate(degree)
    r_image.save(dir1)
    # await asyncio.sleep(0)
    print(f"rotate : {dir1[-5:]}  finished -> ", datetime.now())

# async def save_image(image, dir1):
#     image.save(dir1)


def rotate(dataset, degree):
    num = 0
    while True:
        num += 1
        try:
            os.mkdir(dataset[0] + '/rotated' + str(degree) + "(" + str(num) + ")")
            break
        except:
            continue

    for i in range(1, len(dataset)):
        image_set = Image.open(dataset[i])
        rotated3 = image_set.rotate(degree)
        time.sleep(0)
        rotated3.save(dataset[0] + '/rotated' + str(degree) + "(" + str(num) + ")/" + str(i) + '.png')
    # rotated_list = await asyncio.gather(*[rotate_image(dataset[j], degree,
    #                                                    dataset[0] + '\\rotated' + str(degree) + "(" + str(
    #                                                        num) + ")\\" + str(j) + '.png') for j in
    #                                       range(1, len(dataset))])
    # for i in range(len(rotated_list)):
    #     rotated_list[i].save(dataset[0] + '\\rotated' + str(degree) + "(" + str(num) + ")\\" + str(i) + '.png')
    # await asyncio.gather(
    #     *[save_image(rotated_list[j], dataset[0] + '\\rotated' + str(degree) + "(" + str(num) + ")\\" + str(j) + '.png')
    #       for j in range(0, len(rotated_list))])


start = time.time()
print(start)
z = filter_format("E:\AP-99\\rotated52(1)")
# asyncio.run(rotate(z, 52))
rotate(z, 52)
end = time.time()
print(end)
print("long :", end - start)
