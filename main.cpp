
// #include <opencv2/core.hpp>
#include <opencv4/opencv2/opencv.hpp>
// #include <opencv2/highgui/highgui.hpp>
#include <iostream>
// #include <stdio.h>
using namespace cv;
int main(){
    Mat image = imread("ascii-pineapple.jpg", IMREAD_COLOR);
    
    int b, g, r;
    for(int i=0; i<image.rows;i++){
        for(int j=0; j<image.cols; j++){
            b = image.at<Vec3b>(i, j)[0];
            g = image.at<Vec3b>(i, j)[1];
            r = image.at<Vec3b>(i, j)[2];
        }
    }

    if(image.empty()){
        std::cout<<"Could not read the image: "<<std::endl;
    }

    imshow("Display window", image);

    waitKey(0);
    // if(waitKey(0) == 27){
    //     std::cout<<"Image read successfully"<<std::endl;
    // }
}