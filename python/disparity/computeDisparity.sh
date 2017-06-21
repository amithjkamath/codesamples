#!/bin/bash

# This seems to be the most reliable way to capture images from two webcams connected to the Rpi.
fswebcam -D 1 -d /dev/video0 -r 640x480 --no-banner ./image0.jpg; fswebcam -D 1 -d /dev/video1 -r 640x480 --no-banner ./image1.jpg

# The image names are hard coded to image0.jpg and image1.jpg. The output is called D_L.png
python disparity.py
