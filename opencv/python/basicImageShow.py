# This example shows how basic image I/O can be done using opencv in python. 
# Amith, 01/08

# This imports all the opencv functions/classes
import cv2

# This allows including a command line argument to choose the image.
from sys import argv

script, filename = argv

# This is similar to IPT and imread.
img = cv2.imread(filename)
print "Read image\n"

# Need the next line if doing this interactively in a script.
# cv2.startWindowThread()
# print "Started image window thread"

# This is similar to IPT and imshow.
cv2.imshow('thisWindow',img)
print "Invoked imshow"

# Need to do this to actually show the window and wait for user response.
cv2.waitKey(-1)
print "Issued waitKey"

# This is used to destroy the windows.
cv2.destroyAllWindows()
print "Destroyed all windows"
