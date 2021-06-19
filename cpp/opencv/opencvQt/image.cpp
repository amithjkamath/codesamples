#include "image.h"

#include <iostream> // for cerr.
#include <QImage>
#include <QSize>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

image::image()
{
}

image::~image()
{
    imageData.release();
}

cv::Mat image::getImage() const
{
    return imageData;
}

void image::setImage(cv::Mat imageIn)
{
    if(!imageIn.empty())
        imageData = imageIn;
    else
        std::cerr << "Image: setImage: input image is empty" << std::endl;
}

cv::Mat image::getOriginal() const
{
    return imageOriginal;
}

void image::setOriginal(cv::Mat imageIn)
{
    if(!imageIn.empty())
        imageOriginal = imageIn;
    else
        std::cerr << "Image: setImage: input image is empty" << std::endl;
}

void image::fromFile(QString fileName)
{
    setImage(cv::imread(fileName.toStdString()));
    setOriginal(getImage());
}

bool image::isEmpty()
{
    return imageData.empty();
}

QSize image::getSize()
{
    int width = imageData.cols;
    int height = imageData.rows;
    return QSize(width, height);
}

void image::setSize(int width, int height)
{
    if((width > 0) && (height > 0))
        cv::resize(imageData,imageData,cv::Size(width, height));
    else
        std::cerr << "Image: resize: new size isn't correct!" << std::endl;
}

QImage image::toQImage()
{
 /* Copyright (C) 2012 Jorge Aparicio <jorge.aparicio.r@gmail.com>*/
    cv::Mat src = imageData;
    QImage dest(src.cols, src.rows, QImage::Format_ARGB32);

    const float scale = 255.0;

    if (src.depth() == CV_8U) {
      if (src.channels() == 1) {
        for (int i = 0; i < src.rows; ++i) {
          for (int j = 0; j < src.cols; ++j) {
            int level = src.at<quint8>(i, j);
            dest.setPixel(j, i, qRgb(level, level, level));
          }
        }
      } else if (src.channels() == 3) {
        for (int i = 0; i < src.rows; ++i) {
          for (int j = 0; j < src.cols; ++j) {
            cv::Vec3b bgr = src.at<cv::Vec3b>(i, j);
            dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
          }
        }
      }
    } else if (src.depth() == CV_32F) {
      if (src.channels() == 1) {
        for (int i = 0; i < src.rows; ++i) {
          for (int j = 0; j < src.cols; ++j) {
            int level = scale * src.at<float>(i, j);
            dest.setPixel(j, i, qRgb(level, level, level));
          }
        }
      } else if (src.channels() == 3) {
        for (int i = 0; i < src.rows; ++i) {
          for (int j = 0; j < src.cols; ++j) {
            cv::Vec3f bgr = scale * src.at<cv::Vec3f>(i, j);
            dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
          }
        }
      }
    }

    return dest;
}
