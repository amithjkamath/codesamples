import numpy as np
import cv2
import os


def shiftImage(img, shiftVal):
    """
    Params:
    img: the input image, grayscale, and 2D.
    shiftVal: the number of pixels by which the image needs to be shifted, left to right only. There is no shifting along the vertical axis. This value can be negative or positive, and is only integral.
    Returns: image shifted laterally by shiftVal
    """
    rows, cols = img.shape
    # Create the transformation matrix. [1 0 xshift; 0 1 yshift]: yshift = 0
    tform = np.float32([[1,0,shiftVal],[0,1,0]])
    dst = cv2.warpAffine(img,tform,(cols,rows))
    return dst


def disparity_ssd(L, R, windowLength = 5, disparityMax = 9):
    """Compute disparity map D(y, x) such that: L(y, x) = R(y, x + D(y, x))
    Params:
    L: Grayscale left image, in range [0.0, 1.0]
    R: Grayscale right image, same size as L
    windowHalfLength: parameterizes the window size of the template used to match patches in the two images. Example: if 3, window extends 3 pixels left, 3 right, and includes the center: total length = 3+3+1
    disparityMax: the largest horizontal translation allowed. If there is no clear minumum, this value is returned for disparity.
    Returns: Disparity map, same size as L, R
    """
    filterkernel = np.ones((windowLength, windowLength), np.float32) / (windowLength*windowLength)
    # Pad the image to avoid the gradient like effect at the left and right corners. Pad size equals the maximum disparity limit allowed.
    L = cv2.copyMakeBorder(L,0,0,disparityMax,disparityMax,cv2.BORDER_REPLICATE)
    R = cv2.copyMakeBorder(R,0,0,disparityMax,disparityMax,cv2.BORDER_REPLICATE)
    disArr = np.arange(-disparityMax, disparityMax + 1, 1)
    x, y = L.shape
    D = np.zeros((x, y, len(disArr)), np.float32)
    dispMin = np.zeros((x, y), np.int32)
    for idx in range(0, len(disArr)):
        rshift = shiftImage(R, disArr[idx])
        diff = L - rshift
        diff = np.square(diff)
        out = cv2.filter2D(diff, -1, filterkernel)
        D[:,:,idx] = out
    # Look through the 3D D matrix to extract index of minimum.
    for xidx in range(0, x):
        for yidx in range(0, y):
            dispVals = D[xidx, yidx, :]
            idx = np.argmin(dispVals) - disparityMax # shift negatives.
            dispMin[xidx, yidx] = idx
    # unpad the image
    dispMin = dispMin[:, disparityMax:y-disparityMax]
    # to normalize L and R disparities.
    dispMin = np.absolute(dispMin)
    return dispMin


def disparity_ncorr(L, R, windowLength = 5, disparityMax = 9):
    """Compute disparity map D(y, x) such that: L(y, x) = R(y, x + D(y, x))
    Params:
    L: Grayscale left image, in range [0.0, 1.0]
    R: Grayscale right image, same size as L
    windowHalfLength: parameterizes the window size of the template used to match patches in the two images. Example: if 3, window extends 3 pixels left, 3 right, and includes the center: total length = 3+3+1
    disparityMax: the largest horizontal translation allowed. If there is no clear minumum, this value is returned for disparity.
    Returns: Disparity map, same size as L, R
    """
    # structure similar to SSD: hence no special comments. Lines in the first for loop are the only ones that are different, accounting for the math in computing ncorr.
    filterkernel = np.ones((windowLength, windowLength), np.float32) / (windowLength*windowLength)
    L = cv2.copyMakeBorder(L,0,0,disparityMax,disparityMax,cv2.BORDER_REPLICATE)
    R = cv2.copyMakeBorder(R,0,0,disparityMax,disparityMax,cv2.BORDER_REPLICATE)
    disArr = np.arange(-disparityMax, disparityMax + 1, 1)
    x, y = L.shape
    D = np.zeros((x, y, len(disArr)), np.float32)
    dispMax = np.zeros((x, y), np.int32)
    for idx in range(0, len(disArr)):
        rshift = shiftImage(R, disArr[idx])
        prod = np.multiply(L,rshift)
        squareL = np.square(L)
        squarers = np.square(rshift)
        outprod = cv2.filter2D(prod, -1, filterkernel)
        outl = cv2.filter2D(squareL, -1, filterkernel)
        outrs = cv2.filter2D(squarers, -1, filterkernel)
        # using eps to avoid division by 0.
        out = np.divide(outprod,np.sqrt(np.multiply(outl,outrs))+np.finfo(float).eps)
        D[:,:,idx] = out
    for xidx in range(0, x):
        for yidx in range(0, y):
            dispVals = D[xidx, yidx, :]
            idx = np.argmax(dispVals) - disparityMax
            dispMax[xidx, yidx] = idx
    dispMax = dispMax[:, disparityMax:y-disparityMax]
    dispMax = np.absolute(dispMax)
    return dispMax


def normalize(inputImage):
    """Computes the normalized version of the image, to save out as a file.
    Params:
    inputImage: the image to be normalized.
    Returns: outputImage, which ranges strictly from 0 to 255
    """
    (minVal, maxVal, minLoc, maxLoc) = cv2.minMaxLoc(inputImage)
    inputImage = inputImage - minVal
    # doing this twice, as the maxValue can change after subtracting the min value, and can become 0.
    (minVal, maxVal, minLoc, maxLoc) = cv2.minMaxLoc(inputImage)
    if maxVal != 0:
        outputImage = ((inputImage * 255.0)/ maxVal)
    else:
        outputImage = inputImage
    return outputImage


def main():
    """Run code/call functions to solve problems."""
    print('Computing disparity using the captured images\n')
    # Read images
    frame0 = cv2.imread('./image0.jpg')
    frame1 = cv2.imread('./image1.jpg')

    gray0 = cv2.cvtColor(frame0, cv2.COLOR_BGR2GRAY)
    gray0 = np.float64(gray0) * (1.0/255.0)

    gray1 = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)
    gray1 = np.float64(gray1) * (1.0/255.0)

    # Compute disparity
    D_L = disparity_ncorr(gray0, gray1, 31, 50)
    
    # write images out
    fname = 'D_L.png'
    cv2.imwrite(fname, normalize(D_L))


if __name__ == "__main__":
    main()
