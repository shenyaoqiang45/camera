#!/bin/bash

g++  -o v4l2_test live.c  draw_framebuffer.c video_capture.c \
-I /usr/local/include/opencv4 \
-L /usr/local/lib/ -lopencv_core -lopencv_highgui -lopencv_videoio
