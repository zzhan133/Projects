// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include "Example2_4.h"
#include "Example2_5.h"
//#include <iostream>



int g_slider_position = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos){
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES,pos);
}

int main(int argc, char* argv[])
{
//	std::cout<<argc<<std::endl;
	CvCapture *capture;
	if(argc == 1){
		capture = cvCreateCameraCapture(0);
	}
	else
		capture = cvCreateFileCapture(argv[1]);
	if(!capture)
		return -1;
	cvNamedWindow("Example", CV_WINDOW_AUTOSIZE);
	IplImage* frame;
	while(1){
		frame = cvQueryFrame(capture);
		if(!frame) break;
		cvShowImage("Example", frame);
		char c = cvWaitKey(33);
		if(c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example");
	return 0;
}

/**********************************************************************
//Example 2_3 
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("test.avi");
	int frames = (int) cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
	);
	if(frames != 0) {
		cvCreateTrackbar(
			"position",
			"Example3",
			&g_slider_position,
			frames,
			onTrackbarSlide
			);
	}
	IplImage* frame;
	while(1){
		frame = cvQueryFrame(g_capture);
		if(!frame) break;
		cvShowImage("Example3", frame);
		char c = cvWaitKey(33);
		if(c==27) break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");
*/