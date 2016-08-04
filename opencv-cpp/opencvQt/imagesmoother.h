#ifndef IMAGESMOOTHER_H
#define IMAGESMOOTHER_H

class image;

class imageSmoother
{
public:
    imageSmoother();
    imageSmoother(image* Im);

    void smoothed(int kernelSize);

    void setImage(image* Im);
    image* getImage();
private:
    image* smoothIm;
};

#endif // IMAGESMOOTHER_H
