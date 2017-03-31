#include "imagesmoother.h"

#include <iostream> // for std::cout and std::cerr

#include "image.h"

#include <opencv2/imgproc/imgproc.hpp>

imageSmoother::imageSmoother()
{
    smoothIm = NULL;
}

imageSmoother::imageSmoother(image* Im)
{
    if(!Im->isEmpty())
        smoothIm = Im;
    else
        std::cerr << "Smooth Image: image to load is empty" << std::endl;
}

void imageSmoother::smoothed(int kernelSize)
{
    cv::Mat Im = smoothIm->getImage();
    cv::Mat kernel = cv::Mat::ones( kernelSize, kernelSize, CV_32F )/ (float)(kernelSize*kernelSize);
    cv::filter2D(Im, Im,-1, kernel);
    smoothIm->setImage(Im);
}

void imageSmoother::setImage(image* Im)
{
    if(!Im->isEmpty())
        smoothIm = Im;
    else
        std::cerr << "Smooth Image: setImage: image is empty" << std::endl;
}

image* imageSmoother::getImage()
{
    return smoothIm;
}
