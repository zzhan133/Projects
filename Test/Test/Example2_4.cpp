
#include "stdafx.h"
#include "Example2_4.h"

void example2_4(IplImage* image){
	//Create some windows to show the input
	//and output images in.
	//
	cvNamedWindow("Example4_in");
	cvNamedWindow("Example4_out");
	//Create a window to show our input image
	//
	cvShowImage("Example4_in", image);
	//Create an image to hold the smoothed output
	//
	IplImage* out = cvCreateImage(
			cvGetSize(image),
			IPL_DEPTH_8U,
			3
			);
	//Do the smoothing
	//
	cvSmooth(image, out, CV_GAUSSIAN,3,3);
	
	//Show the smoothed image in the output window
	//
	cvShowImage("Example4_out", out);

	//Be tidy
	//
	cvReleaseImage(&out);

	//Wait for the user to hit a key, then clean up the windows
	//
	cvWaitKey(0);
	cvDestroyWindow("Example4_in");
	cvDestroyWindow("Example4_out");
}
