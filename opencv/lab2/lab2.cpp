// Basic mouse interactions example.
// From: http://opencv-srf.blogspot.com/2011/11/mouse-events.html

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if(event == EVENT_LBUTTONDOWN)
	{
		std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if(event == EVENT_RBUTTONDOWN)
	{
		std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if(event == EVENT_MBUTTONDOWN)
	{
		std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	}
	else if(event == EVENT_MOUSEMOVE)
	{
		std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;
	}
}

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "Error: Image is not specified." << std::endl;
		return -1;
	}	
	// Read image from file 
	Mat img = imread(argv[1]);

	//if fail to read the image
	if ( img.empty() ) 
	{ 
		std::cout << "Error loading the image" << std::endl;
		return -1; 
	}

	//Create a window
	namedWindow("My custom Window", 1);

	//set the callback function for any mouse event
	setMouseCallback("My custom Window", CallBackFunc, NULL);

	//show the image
	imshow("My custom Window", img);

	// Wait until user press some key
	waitKey(0);

	return 0;
}
