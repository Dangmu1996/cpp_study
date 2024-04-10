#include <cuda_runtime.h>
#include <opencv4/opencv2/opencv.hpp>
#include "gaussian_blur.h"


__global__ void gaussianBlurKernel(const uchar3* inputImage, uchar3* outputImage, int width, int height) 
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if (x < width && y < height) {
        float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
        int numPixels = 0;

        for (int offsetY = -1; offsetY <= 1; ++offsetY) {
            for (int offsetX = -1; offsetX <= 1; ++offsetX) {
                int neighborX = x + offsetX;
                int neighborY = y + offsetY;

                if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height) {
                    uchar3 neighborPixel = inputImage[neighborY * width + neighborX];
                    sumR += neighborPixel.x;
                    sumG += neighborPixel.y;
                    sumB += neighborPixel.z;
                    ++numPixels;
                }
            }
        }

        outputImage[y * width + x].x = sumR / numPixels;
        outputImage[y * width + x].y = sumG / numPixels;
        outputImage[y * width + x].z = sumB / numPixels;
    }
}

void gaussianBlurCUDA(const cv::Mat& inputImage, cv::Mat& outputImage) {
    // 이미지를 GPU로 복사
    uchar3* d_inputImage;
    uchar3* d_outputImage;
    size_t numPixels = inputImage.cols * inputImage.rows;
    cudaMalloc(&d_inputImage, numPixels * sizeof(uchar3));
    cudaMalloc(&d_outputImage, numPixels * sizeof(uchar3));
    cudaMemcpy(d_inputImage, inputImage.ptr(), numPixels * sizeof(uchar3), cudaMemcpyHostToDevice);

    // CUDA 커널 실행
    dim3 threadsPerBlock(32, 32);
    dim3 gridSize((inputImage.cols + threadsPerBlock.x - 1) / threadsPerBlock.x, (inputImage.rows + threadsPerBlock.y - 1) / threadsPerBlock.y);
    gaussianBlurKernel<<<gridSize, threadsPerBlock>>>(d_inputImage, d_outputImage, inputImage.cols, inputImage.rows);

    // 결과 이미지를 호스트로 복사
    outputImage.create(inputImage.size(), inputImage.type());
    cudaMemcpy(outputImage.ptr(), d_outputImage, numPixels * sizeof(uchar3), cudaMemcpyDeviceToHost);

    // 메모리 해제
    cudaFree(d_inputImage);
    cudaFree(d_outputImage);
}
