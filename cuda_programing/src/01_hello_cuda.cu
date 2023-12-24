#include <cstdio>

using namespace std;

__global__ void cuda_hello(){
    printf("hello world from gpu!\n");
}

int main(){
    cuda_hello<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}