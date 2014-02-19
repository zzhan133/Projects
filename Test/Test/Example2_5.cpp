#include "stdafx.h"
#include "Example2_5.h"
IplImage* doPyrDown( IplImage* in, int filter){
	//best to make sure input image is divisible by two.
	//
	assert(in->width%2 == 0 && in->height%2 == 0);
	IplImage* out = cvCreateImage(
			cvSize(in->width/2, in->height/2),
			in->depth,
			in->nChannels);
	cvPyrDown(in, out);
	return out;
}

/*
	IplImage* img = cvLoadImage("baboon.jpg");
//	example2_4(img);
	cvNamedWindow("Example5_in");
	cvNamedWindow("Example5_out");
	cvShowImage("Example5_in", img);
	IplImage* out = doPyrDown(img);
	cvShowImage("Example5_out",out);
	cvWaitKey(0);
	cvDestroyWindow("Example5_in");
	cvDestroyWindow("Example5_out");
	cvReleaseImage(&out);
	cvReleaseImage(&img);
*/