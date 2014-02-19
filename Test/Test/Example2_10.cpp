//Convert a video to grayscale
//argv[1]: input video file
//argv[2]: name of the new output file
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	cvNamedWindow("Example2_10",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Log_Polar",CV_WINDOW_AUTOSIZE);
	CvCapture* capture = 0;
	capture = cvCreateFileCapture("test.avi");
	if(!capture)
	{
		return -1;
	}
	IplImage *bgr_frame = cvQueryFrame(capture); //Init the video read
	double fps = cvGetCaptureProperty(
			capture,
			CV_CAP_PROP_FPS
			);
	//output fps value
	std::cout<<"fps: "<<fps<<std::endl;

	CvSize size = cvSize(
			(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
			(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
			);
	std::cout<<"width: "<<size.width<<" "<<"height: "<<size.height<<std::endl;

	CvVideoWriter *writer = cvCreateVideoWriter(
			"writer.mjpg",
			CV_FOURCC('M','J','P','G'),
			fps,
			size
			);
	IplImage* gray_frame = cvCreateImage(
        size,
        IPL_DEPTH_8U,
        1
    ); 

	IplImage *logpolar_frame = cvCreateImage(
			size,
			IPL_DEPTH_8U,
			3
			);
	while( (bgr_frame = cvQueryFrame(capture)) != NULL){
		////////////////////////////////////////////////////////////////////////////////////////
		cvShowImage( "Example2_10", bgr_frame );
        cvConvertImage(   //We never make use of this gray image
            bgr_frame,
            gray_frame,
            CV_RGB2GRAY
        ); 
		////////////////////////////////////////////////////////////////////////////////////////
		cvLogPolar( bgr_frame, logpolar_frame,
				cvPoint2D32f(bgr_frame->width/2,bgr_frame->height/2),
					40,
					CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
				cvShowImage( "Log_Polar", logpolar_frame ); 
				cvWriteFrame( writer, logpolar_frame);	
				char c = cvWaitKey(10);
				if(c == 27) break;
	}
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&gray_frame);
	cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
