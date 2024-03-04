#include <iostream>

using namespace std;

__global__ void VecAdd(float* A, float* B, float* C)
{
    // thread index로 더하기
    int i = threadIdx.x; // 이렇게 하면 thread index가 계산이 된다고 함.
    C[i] = A[i] + B[i];
}

/*    
1. 호스트 메모리에서 데이터 배열을 위한 공간을 할당한다.
2. 디바이스 메모리에 데이터 배열을 위한 공간을 할당한다.
3. 호스트에서 디바이스 메모리로 데이터를 복사합니다.
4. GPU 커널을 실행합니다.
5. 계산된 결과를 디바이스에서 호스트로 다시 복사합니다.
6. 디바이스 메모리 할당을 해제합니다.
*/

int main()
{
    float a[3] = {1, 1, 1};
    float b[3] = {1, 2, 3};
    float c[3];

    float *d_A, *d_B, *d_C;
    int size = 3 * sizeof(float);

    // 디바이스 메모리 할당
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    // 호스트에서 디바이스로 데이터 복사
    cudaMemcpy(d_A, a, size, cudaMemcpyHostToDevice); 
    cudaMemcpy(d_B, b, size, cudaMemcpyHostToDevice);

    // 커널 실행
    VecAdd<<<1, 3>>>(d_A, d_B, d_C);

    // 디바이스에서 호스트로 결과 복사
    cudaMemcpy(c, d_C, size, cudaMemcpyDeviceToHost); //cudaMemcpy() 함수 자체가 블로킹 호출이기 때문에, GPU에서 커널 실행이 완료되기 전까지는 CPU 쓰레드가 대기 상태가 된다.

    cout << c[0] << ", "
         << c[1] << ", "
         << c[2] << ", "
         << endl;

    // 디바이스 메모리 해제
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}