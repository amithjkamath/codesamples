#ifndef IMAGEBRIGHTENER_H
#define IMAGEBRIGHTENER_H

class image;

class imageBrightener
{
public:
    imageBrightener();
    imageBrightener(image* Im);

    void brighten(int value);

    void setImage(image* Im);
    image* getImage();
private:
    image* brightenIm;
};

#endif // IMAGEBRIGHTENER_H
