#include <cstdio>

using namespace std;

// 예를 kernel이라고 부름
__global__ void cuda_hello(){
    printf("hello world from gpu!\n");
}

int main(){
    cuda_hello<<<1,1>>>(); // <block, theard> cuda hello 실행
    cudaDeviceSynchronize(); // 수는 CUDA 프로그램에서 모든 GPU 작업이 완료될 때까지 CPU 쓰레드의 실행을 차단(대기)하게 만드는 역할
    return 0;
}