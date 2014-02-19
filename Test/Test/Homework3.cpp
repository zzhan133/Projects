#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <iostream>

//The function is from the example 2_5
IplImage* doPyrDown(
  IplImage* in,
  int       filter = IPL_GAUSSIAN_5x5)
{

    // Best to make sure input image is divisible by two.
    //
    assert( in->width%2 == 0 && in->height%2 == 0 );

    IplImage* out = cvCreateImage( 
        cvSize( in->width/2, in->height/2 ),
        in->depth,
        in->nChannels
    );
    cvPyrDown( in, out );
    return( out );
};


int main( int argc, char** argv ) { 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //get capture from the camera.
	cvNamedWindow( "Example2_9", CV_WINDOW_AUTOSIZE );
    CvCapture* capture = 0;
    if (argc==1) {
        capture = cvCreateCameraCapture( 0 );
    } else {
        capture = cvCreateFileCapture( argv[1] );
    }
    assert( capture != NULL ); 

    //get the parameters from the camera
	IplImage *bgr_frame = cvQueryFrame(capture); //Init the video read
	double fps = cvGetCaptureProperty(
			capture,
			CV_CAP_PROP_FPS
			);
	if(fps == 0)   //According to the documentation, fps means the framerate.
		fps = 10;
	//output fps value
	std::cout<<"fps: "<<fps<<std::endl;

	CvSize size = cvSize(
			(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
			(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
			);
	std::cout<<"width: "<<size.width<<" "<<"height: "<<size.height<<std::endl;
	//write the video file
	CvVideoWriter *writer = cvCreateVideoWriter(
			"homework3.mjpg",
			CV_FOURCC('M','J','P','G'),
			fps,
			size
			);

	while(1){
		////////////////////////////////////////////////////////////////////////////////////////
		//cvShowImage( "Example2_10", bgr_frame );
		bgr_frame = cvQueryFrame(capture);
		if(!bgr_frame) break;
//		bgr_frame = doPyrDown(bgr_frame);
		cvWriteFrame( writer, bgr_frame);
		cvShowImage( "Example2_9", bgr_frame );
		char c = cvWaitKey(10);
		if(c == 27) break;
	}
	cvDestroyWindow( "Example2_9" ); 
	cvReleaseVideoWriter(&writer);
//	cvReleaseImage(&bgr_frame);	
	cvReleaseCapture(&capture);
    	return 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*cvNamedWindow( "Example2_9", CV_WINDOW_AUTOSIZE );
    CvCapture* capture;
    if (argc==1) {
        capture = cvCreateCameraCapture( 0 );
    } else {
        capture = cvCreateFileCapture( argv[1] );
    }
    assert( capture != NULL );

    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) break;
        cvShowImage( "Example2_9", frame );
        char c = cvWaitKey(10);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Example2_9" ); 
	return 0;*/
}
