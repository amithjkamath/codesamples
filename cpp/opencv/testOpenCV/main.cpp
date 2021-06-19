#include "iostream"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
   IplImage *image = cvLoadImage("C:\\chelsea.jpg",1);
   cvShowImage("TEST",image);
   waitKey();
   return 0;
}
