/*
 ============================================================================
 Name        : live.c
 Author      : LincolnHard
 Version     :
 Copyright   : free and open
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "video_capture.h"
#include "draw_framebuffer.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp> 

using namespace cv;
using namespace std;


void cvt2BGRMat(unsigned char*src, Mat &dst)
{
    if(!src)
	    return;
    vector<Mat> bgr_planes;
    split( dst, bgr_planes );
    int i = 0; 
	for(int y = 0; y < IM_HEIGHT; y++)
	{
		for(int x = 0; x < IM_WIDTH; x++)
		{
		    bgr_planes[0].at<unsigned char>(y,x) = src[3*i];
		    bgr_planes[1].at<unsigned char>(y,x) = src[3*i+1];
		    bgr_planes[2].at<unsigned char>(y,x) = src[3*i+2];
			i++;
		}
	}
    merge(bgr_planes, dst);
	return;
}

int main(void) {
    unsigned char src_image[IM_WIDTH * IM_HEIGHT * 3];
    init_framebuffer();
	init_video_capture();
	char key = 0;

	for(; ;){
		key = video_capture(src_image);
		draw_framebuffer(src_image);
		Mat frame(IM_WIDTH, IM_HEIGHT, CV_8UC3);
        cvt2BGRMat(src_image, frame);
		imshow("Video", frame);
        if (waitKey(30) >= 0) 
		    break;
		if(key == 'q'){
			break;
		}
	}
    free_video_capture();
	free_framebuffer();
	return EXIT_SUCCESS;
}
