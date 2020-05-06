#!/bin/bash

g++ -o webcam_test webcam_test.cpp \
-I /usr/local/include/opencv4 \
-L /usr/local/lib/ -lopencv_core -lopencv_highgui -lopencv_videoio
