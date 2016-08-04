////////////////////////////////////////////////////////////////////////
//
// hello-world.cpp
//
// This is a simple, introductory OpenCV program. The program reads an
// image from a file, inverts it, and displays the result. 
//
////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

void mouseHandler(int event, int x, int y, int flags, void* param);

int main(int argc, char *argv[])
{
  printf("reached 19\n");
  IplImage* img = 0; 
  IplImage* resImg = 0;
  IplImage* cloneimg = 0;
  int a[] = { 1, 0, 0,
               0, 5, 0,
               0, 0, 1 };
  CvMat* mat;
  printf("reached 27\n");
  //cvInitMatHeader(mat,3,3,CV_8UC1,a,CV_AUTOSTEP);
   printf("reached 29\n"); 
  int height,width,step,channels;
  uchar *data;
  int i,j,k;
  printf("reached 32\n");
  if(argc<2){
    printf("Usage: main <image-file-name>\n\7");
    exit(0);
  }

  printf("reached 37\n");
  // load an image  
  img=cvLoadImage(argv[1],-1);
  if(!img){
    printf("Could not load image file: %s\n",argv[1]);
    exit(0);
  }
  printf("reached 44\n");
  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  printf("Processing a %dx%d image with %d channels\n",height,width,channels); 

  // create a window
  cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE); 
  cvNamedWindow("mainWin2", CV_WINDOW_AUTOSIZE); 
  cvMoveWindow("mainWin", 500, 500);
  printf("reached 57\n");
  // invert the image
  //for(i=0;i<height;i++) for(j=0;j<width;j++) for(k=0;k<channels;k++)
  //  data[i*step+j*channels+k]=255-data[i*step+j*channels+k];

  cloneimg = cvCreateImage(cvSize(width,height),IPL_DEPTH_8U, 1); //These depths are needed to be maintained.
  cvCvtColor(img,cloneimg,CV_BGR2GRAY);
  resImg = cvCreateImage(cvSize(width,height),IPL_DEPTH_16S, 1);
// This is important. out has to have IPL_DEPTH_16S for laplace,sobel,canny to work.
  cvFilter2D(cloneimg,resImg,mat,cvPoint(0,0));

  // show the image
  cvShowImage("mainWin", img );
  cvShowImage("mainWin2",resImg);
  printf("reached 71\n");
  // wait for a key
  //cvWaitKey(0);
  int mouseparam = 1;
  cvSetMouseCallback("mainWin",mouseHandler,&mouseparam);
 

  cvWaitKey(0);
  // release the image
  cvReleaseImage(&img );
  cvReleaseImage(&cloneimg);
  cvReleaseImage(&resImg);
  cvReleaseMat(&mat);
  cvDestroyAllWindows();
  return 0;
}

void mouseHandler(int event, int x, int y, int flags, void* param)
  {
    switch(event){
      case CV_EVENT_RBUTTONUP:
          printf("Right button up\n");
        break;

      case CV_EVENT_LBUTTONUP:
        printf("Left button up\n");
        break;
    }
  }
