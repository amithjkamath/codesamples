// for all the image manipulation functions.
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// for cout et al
#include <iostream>
// for atoi
#include <cstdlib>

using namespace cv;

int main( int argc, const char** argv )
{

	if(argc != 2)
	{
		std::cout << "Error: Input image not included. Try again." << std::endl;
		return -1;
	}

	Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR); // CV_LOAD_GRAYSCALE for single plane.

	if (img.empty())
	{
		std::cout << "Image cannot be loaded." << std::endl;
		return -1;
	}
	
	int maxVal = 0;
	int minVal = 255;
	
	for(int i = 0; i < img.rows; i++)
	{
		for(int j = 0; j < img.cols; j++)
		{ // note that the image is stored as BGR. 
		// img.at<cv::Vec3b>(xLocation, yLocation)[planeIndex] 
		// plane index: 0 1 2 for B, G, R.
			if((int)img.at<cv::Vec3b>(i,j)[2] < minVal)
				minVal = (int)img.at<cv::Vec3b>(i,j)[2];
			if((int)img.at<cv::Vec3b>(i,j)[2] > maxVal)
				maxVal = (int)img.at<cv::Vec3b>(i,j)[2];
		}
	}
	
	std::cout << "Max value in Red plane of image is " << maxVal << std::endl;
	std::cout << "Min: value in Red plane of image is " << minVal << std::endl;
	
	maxVal = 0;
	minVal = 255;
	
	for(int i = 0; i < img.rows; i++)
	{
		for(int j = 0; j < img.cols; j++)
		{ // note that the image is stored as BGR. 
		// img.at<cv::Vec3b>(xLocation, yLocation)[planeIndex] 
		// plane index: 0 1 2 for B, G, R.
			if((int)img.at<cv::Vec3b>(i,j)[0] < minVal)
				minVal = (int)img.at<cv::Vec3b>(i,j)[0];
			if((int)img.at<cv::Vec3b>(i,j)[0] > maxVal)
				maxVal = (int)img.at<cv::Vec3b>(i,j)[0];
		}
	}
	
	std::cout << "Max value in Blue plane of image is " << maxVal << std::endl;
	std::cout << "Min: value in Blue plane of image is " << minVal << std::endl;
	
	for(int i = 0; i < img.rows; i++)
	{
		for(int j = 0; j < img.cols; j++)
		{ // note that the image is stored as BGR. 
		// img.at<cv::Vec3b>(xLocation, yLocation)[planeIndex] 
		// plane index: 0 1 2 for B, G, R.
			img.at<cv::Vec3b>(i,j)[0] *= 1.5;
		}
	}	
	
	namedWindow("Original Image", CV_WINDOW_AUTOSIZE);

	imshow("Original Image", img);

	waitKey(0);

	destroyAllWindows(); //destroy all open windows

	return 0;
}
