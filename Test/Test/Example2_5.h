#pragma once
#include "stdAfx.h"
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
IplImage* doPyrDown( IplImage* in, int filter = IPL_GAUSSIAN_5x5);
