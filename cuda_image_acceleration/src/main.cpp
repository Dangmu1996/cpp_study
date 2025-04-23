#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include "gaussian_blur.h"

using namespace std;

int main()
{
    cv::Mat inputImage = cv::imread("../data/gpt.png", cv::IMREAD_COLOR);
    if(inputImage.empty()){
        cerr << "failed to load input image" << endl; 
    }

    // CUDA로 Gaussian 블러링 수행
    cv::Mat blurredCUDA;
    gaussianBlurCUDA(inputImage, blurredCUDA);


    // 결과 이미지 저장
    cv::imwrite("../data/outpout_cuda.png", blurredCUDA);

    return 0;

}