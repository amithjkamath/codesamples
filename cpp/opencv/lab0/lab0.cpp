///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     if(argc != 2)
     {
          cout << "Error: input image is not specified on command line." << endl;
          return -1;
     }
     Mat img = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED); //read the image data specified in the input and store it in 'img'

     if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }

     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     GaussianBlur(img, img,cvSize(5,5), 20);
     imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(0); //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
