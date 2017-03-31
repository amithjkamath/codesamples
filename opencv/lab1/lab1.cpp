// for all the image manipulation functions.
#include "opencv2/highgui/highgui.hpp"
// for cout et al
#include <iostream>
// for atoi
#include <cstdlib>

using namespace cv;

int main( int argc, const char** argv )
{

	if(argc != 3)
	{
		std::cout << "Error: Input image or arguments not included. Try again." << std::endl;
		std::cout << "Usage: ./program imageFileName brightnessValue" << std::endl;
		return -1;
	}

	Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	if (img.empty())
	{
		std::cout << "Image cannot be loaded." << std::endl;
		return -1;
	}

	Mat imgH = img + Scalar(atoi(argv[2]), atoi(argv[2]), atoi(argv[2])); //increase the brightness

	Mat imgL = img + Scalar(-atoi(argv[2]), -atoi(argv[2]), -atoi(argv[2])); //decrease the brightness

	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
	namedWindow("Higher Brightness", CV_WINDOW_AUTOSIZE);
	namedWindow("Lower Brightness", CV_WINDOW_AUTOSIZE);

	imshow("Original Image", img);
	imshow("Higher Brightness", imgH);
	imshow("Lower Brightness", imgL);

	waitKey(0);

	destroyAllWindows(); //destroy all open windows

	return 0;
}
