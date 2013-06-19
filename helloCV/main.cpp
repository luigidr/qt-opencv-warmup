#include <opencv.hpp>
#include <iostream>

//the namespace used by OpenCV 2.x
using namespace cv;

int main()
{
    //read an image
    //TODO: change path
    Mat image = imread("image.jpg");
    //without "using namespace cv" the previous line should be:
    //cv::Mat image = cv::imread("image.jpg");

    if(!image.data){
        //no image has been created...
        std::cout<<"Image not found!"<<std::endl;
        return 1;
    }

    //create an image window named "Hello CV"
    namedWindow("Hello CV");

    //now, show the image on window
    imshow("Hello CV", image);

    //wait a key pressed for 5000 ms
    waitKey(5000);

    return 0;
}
