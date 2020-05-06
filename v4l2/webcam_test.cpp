#include <iostream>
#include <string>
#include <sstream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp> 

using namespace cv;
using namespace std;

const char* keys = 
{
    "{help h usage ? | | print this message}"
    "{@video | | Video file, if not defined try to use webcamera}"
};

int main(int argc, const char** argv)
{
    CommandLineParser parser(argc, argv, keys);
    parser.about("Reading a video and camera v1.0.0");

    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    String videoFile = parser.get<String>(0);

    if (!parser.check())
    {
        parser.printErrors();
        return 0;
    }

    VideoCapture cap; 
    if (videoFile != "")
    {
        cap.open(videoFile);// read a video file
    }else {
        cap.open(0);// read the default caera
    }
    if (!cap.isOpened())// check if we succeeded
    {
        return -1;
    }

    namedWindow("Video", 1);
    while (1)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("Video", frame);
        if (waitKey(30) >= 0) break;
    }

    // Release the camera or video file
    cap.release();
    return 0;
}