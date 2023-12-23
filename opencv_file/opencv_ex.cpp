#include <iostream>
#include "opencv2/opencv.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout<<"Usage: opencv_ex test.jpg"<<std::endl;
        return -1;
    }

    cv::Mat img;
    img = cv::imread(argv[1]);
    if(img.empty())
    {
        std::cout<<"The file is not existed."<<std::endl;
        return -2;
    }
    std::cout<< img.rows <<" " << img.cols << std::endl;

    cv::imshow("opencv_ex", img);
    cv::waitKey(0);
    return 0;
}
