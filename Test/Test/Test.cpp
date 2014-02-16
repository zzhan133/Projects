// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "highgui.h"

int _tmain(int argc, _TCHAR* argv[])
{
/*	const char* imagename = "baboon.jpg"; //the input image location 
	cv::Mat img = cv::imread(imagename); 
	if(img.empty()) 
		return -1; 
	if(!img.data) 
		return -1; 
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE); 
	cv::imshow("image", img); 
	cv::waitKey();
*/
//	IplImage* img = cvLoadImage("baboon.jpg");
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("test.avi");
	IplImage* frame;
	while(1){
		frame = cvQueryFrame(capture);
		if(!frame) break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(33);
		if(c==27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
	return 0;
}

