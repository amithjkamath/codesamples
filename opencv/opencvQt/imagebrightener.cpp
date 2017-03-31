#include "imagebrightener.h"

#include <iostream> // for std::cout and std::cerr

#include "image.h"

#include <opencv2/imgproc/imgproc.hpp>

imageBrightener::imageBrightener()
{
    brightenIm = NULL;
}

imageBrightener::imageBrightener(image* Im)
{
    if(!Im->isEmpty())
        brightenIm = Im;
    else
        std::cerr << "Smooth Image: image to load is empty" << std::endl;
}

void imageBrightener::brighten(int value)
{
    cv::Mat Im = brightenIm->getImage();
    Im = Im + cv::Scalar(value,value,value);
    brightenIm->setImage(Im);
}

void imageBrightener::setImage(image* Im)
{
    if(!Im->isEmpty())
        brightenIm = Im;
    else
        std::cerr << "Smooth Image: setImage: image is empty" << std::endl;
}

image* imageBrightener::getImage()
{
    return brightenIm;
}
