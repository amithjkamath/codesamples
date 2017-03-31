// Auto-generated C Code - S2i Harpia
/*
*	In order to compile this source code run, in a terminal window, the following command:
*	gcc sourceCodeName.c `pkg-config --libs --cflags opencv` -o outputProgramName
*	
*	the `pkg-config ... opencv` parameter is a inline command that returns the path to both 
*	the libraries and the headers necessary when using opencv. The command also returns other necessary compiler options.
*/
// header:
#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <cvaux.h>
#include <highgui.h>
#include <math.h>

#define XDIM 1366
#define YDIM 768
#define FPSHERE 6
#define PI 3.1415926535898

CvPoint centro; // used by getcenter and subsequently in the main code to give mouse coordinates.
CvPoint center[1500];

int lowlim_x, lowlim_y, hilim_x, hilim_y, countx, county;

double rads(double degs)
{
	return (PI/180 * degs);
}
		

int GetColor(IplImage * imagem, int x, int y)
{
	return   (int)(((uchar*)(imagem->imageData + imagem->widthStep*y))[x]);
}

void SetColor(IplImage * imagem, int x, int y, uchar color)
{
	((uchar*)(imagem->imageData + imagem->widthStep*y))[x] = color;
}


void CheckImg(IplImage * img, uchar c_value, uchar tolerance)
{
	uchar min,max;
	int y_It,x_It;
	if((int)c_value < (int)tolerance) // checks for tolerance to be a meaningful value.
		tolerance = c_value;

	if(((int)c_value+(int)tolerance) > 255) // another check.
		tolerance = 255 - c_value;

	min = c_value - tolerance;
	max = c_value + tolerance;

	for(y_It=0;y_It<(img->height);y_It++) // where the mask is made..
		for(x_It=0;x_It<(img->width);x_It++)
		{
				uchar val;
				val = GetColor(img,x_It,y_It);
				if(val >= min && val <= max)
					SetColor(img,x_It,y_It,255);
				else
					SetColor(img,x_It,y_It,0);
		}
}

CvPoint GetCenter(IplImage * src, long int * nOfPts)//, long int * numOfPoints)
{
	long int numOfMatchingPoints;
	long int posXsum;
	long int posYsum;
	int x_It, y_It;
	CvPoint Center;
	
	posXsum = 0;
	posYsum = 0;
	numOfMatchingPoints = 0;

	for(y_It=0;y_It<(src->height);y_It++)
		for(x_It=0;x_It<(src->width);x_It++)
			if(GetColor(src,x_It,y_It))
			{
				posXsum += x_It;
				posYsum += y_It;
				numOfMatchingPoints++;
			}

	if(numOfMatchingPoints > 0)
	{
		Center.x = (int)(posXsum/numOfMatchingPoints);
		Center.y = (int)(posYsum/numOfMatchingPoints);
	}
	else
		numOfMatchingPoints = -1;
// 	(*numOfPoints) = numOfMatchingPoints;
	if(nOfPts)
		*nOfPts = numOfMatchingPoints;

	return Center;
}


double dist22Points(CvPoint a, CvPoint b)
{
	int xD,yD;
	xD = a.x - b.x;
	yD = a.y - b.y;

	xD = (xD>0)?xD:-xD;
	yD = (yD>0)?yD:-yD;

	return (double)(xD*xD + yD*yD);
}

double GetVariance(IplImage * src,CvPoint center)//, long int * numOfPoints)
{
	long int numOfMatchingPoints;
	double distSquaresSum;
	double variance;
	int x_It,y_It;

	numOfMatchingPoints = 0;
	distSquaresSum = 0.0;


	for(y_It=0;y_It<(src->height);y_It++)
		for(x_It=0;x_It<(src->width);x_It++)
			if(GetColor(src,x_It,y_It))
			{
				numOfMatchingPoints++;
				distSquaresSum += dist22Points(center,cvPoint(x_It,y_It));
			}

	if(numOfMatchingPoints)
		variance = distSquaresSum/numOfMatchingPoints;
	else
		variance = -1;


	return variance;
}

long int CheckForColor(IplImage * src, IplImage * dst, uchar * c_value, uchar * tolerance, CvPoint * pointCenter, double * variance)
{
	uchar B,B_T,G,G_T,R,R_T;
	int i;
	long int numOfPoints;
	IplImage * m_pChans[3] = {NULL,NULL,NULL};

	numOfPoints = 0;

	B = c_value[0];
	G = c_value[1];
	R = c_value[2];

	B_T = tolerance[0];
	G_T = tolerance[1];
	R_T = tolerance[2];

	for(i=0;i<3;i++)
		m_pChans[i] = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U, 1);

	cvSplit(src,m_pChans[0],m_pChans[1],m_pChans[2], NULL);

	CheckImg(m_pChans[0],B,B_T);
	CheckImg(m_pChans[1],G,G_T);
	CheckImg(m_pChans[2],R,R_T);

	cvAnd(m_pChans[0], m_pChans[1], dst, NULL );
	cvAnd(m_pChans[2], dst, dst, NULL );

	centro = GetCenter(dst,&numOfPoints);//,&numOfPoints);

	if(numOfPoints != -1)
		*variance = GetVariance(dst,centro);

	pointCenter->x = centro.x;
	pointCenter->y = centro.y;

	cvReleaseImage( &m_pChans[0] );
	cvReleaseImage( &m_pChans[1] );
	cvReleaseImage( &m_pChans[2] );

	return numOfPoints;
}
			
int main(int argc, char ** argv)
{
	//declaration block
IplImage * block4_img_o1 = NULL;

IplImage * block5_img_o1 = NULL;

IplImage * block5_img_i1 = NULL;
IplImage * block5_img_o4 = NULL;

CvPoint block5_point_o1;

uchar block5c_value[3] = {40.0,160.0,160.0};
uchar block5tolerance[3] = {30.0,40.0,40.0};

double block5_double_o2;
double block5_double_o3;
double block11_double_i1;
double block11_double_o1;

int i, counter;

int end;  
end = 0; 
int key; 

	CvCapture * block4_capture = NULL; 
 	IplImage * block4_frame = NULL; 
	cvSetCaptureProperty(block4_capture, CV_CAP_PROP_FPS, FPSHERE); //Set frames per second here!
 	block4_capture = cvCaptureFromCAM(0); 

while(!end) 
 {	 
	cvGrabFrame(block4_capture); 
 	block4_frame = cvRetrieveFrame(block4_capture,0); 

	//execution block
	//Weight: 1
	// Live Mode 
	block4_img_o1 = cvCloneImage(block4_frame);
	block5_img_i1 = cvCloneImage(block4_img_o1);// IMAGE conection
	//Weight: 2

	for(i=25;i>2;i--){
		center[i].x = center[i-1].x;
		center[i].y = center[i-1].y;
	}
	center[1].x = centro.x;
	center[1].y = centro.y;
	

	if(block5_img_i1){
		IplImage * block5_img_t1 = cvCreateImage(cvGetSize(block5_img_i1),IPL_DEPTH_8U, 1);
			if(!block5_img_o4)	block5_img_o4 = cvCloneImage(block5_img_i1);
			else	cvCopy(block5_img_i1,block5_img_o4,0);
		block5_double_o2 = CheckForColor(block5_img_i1, block5_img_t1, block5c_value, block5tolerance, &block5_point_o1, &block5_double_o3);

		// This is where centro is updated!
		cvCircle(block5_img_o4,block5_point_o1,8,cvScalarAll(255),4,8,0);
        	cvReleaseImage(&block5_img_t1);
			}
	block11_double_i1 = block5_double_o2;// DOUBLE conection
	//Weight: 3

	if(centro.x > 0 && centro.y > 0 && centro.x < XDIM && centro.y < YDIM){

	if(centro.x < 0) centro.x = XDIM/4;
	if(centro.y < 0) centro.y = YDIM/2;
	if(centro.x > 1280) centro.x = XDIM/4;
	if(centro.y > 800) centro.y = YDIM/2;

	char outPutStr[100];
	snprintf(outPutStr,100,"export CENTX=%d; export CENTY=%d;echo Current: $CENTX $CENTY; xte 'mousemove %d %d';",XDIM - (int)(centro.x*(float)(XDIM/640)),(int)(centro.y*(float)(YDIM/480)),(XDIM - (int)(centro.x*(float)(XDIM/640))),(int)(centro.y*(float)(XDIM/480)));	
	system(outPutStr);
	
	//char outPutStr2[100];
	//snprintf(outPutStr2,100,"export CENTXS=%d; export CENTYS=%d;echo past1: $CENTXS $CENTYS;",1280 - int(center[1].x*(float)(1280/640)),int(center[1].y*(float)(800/480)));	
	//system(outPutStr2);

	//char outPutStr3[100];
	//snprintf(outPutStr3,100,"export CENTXSS=%d; export CENTYSS=%d;echo past2: $CENTXSS $CENTYSS;",1280 - int(center[5].x*(float)(1280/640)),int(center[5].y*(float)(800/480)));	
	//system(outPutStr3);
	}

	lowlim_x =  centro.x - 10;
	hilim_x = centro.x + 10;
	lowlim_y = centro.y - 10;
	hilim_y = centro.y + 10;

	countx = 0;
	county = 0;
	for(i=1;i<=25;i++){
		if(lowlim_x < center[i].x && center[i].x < hilim_x) countx++;
		if(lowlim_y < center[i].y && center[i].y < hilim_y) county++;
	}

	counter++; // for the clicks. This works but has to be modified for better control.

	if(countx > 8 && county > 8 && counter > 25){
	//if(1){
	
	char outPutStr4[100];
	snprintf(outPutStr4,100,"export CENTXC=%d; export CENTYC=%d;echo Current: $CENTXC $CENTYC; xte 'mouseclick 1';",XDIM - (int)(centro.x*(float)(XDIM/640)),(int)(centro.y*(float)(XDIM/480)));	
	system(outPutStr4);

	counter = 0; 
	}

	block11_double_o1 = block11_double_i1;

	if(block5_img_i1){
	block5_img_o1 = cvCloneImage(block5_img_i1);
	cvFlip(block5_img_o1, NULL, 1);
	cvNamedWindow("block5_img_o1",CV_WINDOW_AUTOSIZE ); 
	cvShowImage("block5_img_o1",block5_img_o1);} 
	//Weight: 3

	//cvNamedWindow("Control Window",CV_WINDOW_AUTOSIZE);
	key = cvWaitKey(200);
	 if(key != -1) end = 1;
	//deallocation block
	cvReleaseImage(&block4_img_o1);
	cvReleaseImage(&block5_img_o4);
	cvReleaseImage(&block5_img_i1);
	//nothing to deallocate
 } // end of while loop.

cvReleaseCapture(&block4_capture);

return 0;
} //closing main()
