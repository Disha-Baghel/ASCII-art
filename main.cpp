
// #include <opencv2/core.hpp>
#include <opencv4/opencv2/opencv.hpp>
// #include <opencv2/highgui/highgui.hpp>
#include <iostream>
// #include<string.h>
// #include <stdio.h>
using namespace cv;
int main(){
    Mat image = imread("ascii-pineapple.jpg", IMREAD_UNCHANGED);
    
    if(image.empty()){
        std::cout<<"Could not read the image: "<<std::endl;
    }

    int **brightness= new int* [image.rows];
    for(int i=0; i<image.rows; i++){
        brightness[i] = new int[image.cols];
    }

    String ascii = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int b, g, r, average;
    for(int i=0; i<image.rows;i++){
        for(int j=0; j<image.cols; j++){
            r = image.at<Vec3b>(i, j)[0];
            g = image.at<Vec3b>(i, j)[1];
            b = image.at<Vec3b>(i, j)[2];
            
            average = (r+g+b)/3;
            brightness[i][j] = average;
        }
    } 

    for(int i=0; i<image.rows; i++){
        for(int j=0; j<image.cols; j++){
            std::cout<<brightness[i][j];
        }
        std::cout<<std::endl;
    }

    int height, width;
    height = image.size[0];
    width = image.size[1];

    std::cout<<"Image Height: "<<height<<std::endl;
    std::cout<<"Image Width: "<<width<<std::endl;


    imshow("Display window", image);

    waitKey(0);
    // if(waitKey(0) == 27){
    //     std::cout<<"Image read successfully"<<std::endl;
    // }
}