// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "highgui.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const char* imagename = "E:/baboon.jpg"; //the input image location 
	cv::Mat img = cv::imread(imagename); 
	if(img.empty()) 
		return -1; 
	if(!img.data) 
		return -1; 
	cv::namedWindow("image", CV_WINDOW_AUTOSIZE); 
	cv::imshow("image", img); 
	cv::waitKey();
	return 0;
}

