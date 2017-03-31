#ifndef IMAGE_H
#define IMAGE_H

#include <QString>  // for filename
#include <QSize>

#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

class QImage;

class image
{
public:
    image();
    ~image();

    cv::Mat getImage() const;
    void setImage(cv::Mat imageIn);

    cv::Mat getOriginal() const;
    void setOriginal(cv::Mat imageIn);

    bool isEmpty();
    void fromFile(QString fileName);

    QSize getSize();
    void setSize(int width, int height);
    QImage toQImage();

private:
    cv::Mat imageData;
    cv::Mat imageOriginal;
};

#endif // IMAGE_H
