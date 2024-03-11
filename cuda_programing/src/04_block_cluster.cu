#include <iostream>
#include <cuda_runtime.h>

using namespace std;

const int N = 2;
const int M = 2;

// Kernel definition
__global__ void addArrays(float *input1, float *input2, float *output)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int idy = threadIdx.y + blockIdx.y * blockDim.y;
    int idz = threadIdx.z + blockIdx.z * blockDim.z;

    int index = idx + idy * N + idz * N * M;

    if (idx < N && idy < M && idz < M)
    {
        output[index] = input1[index] + input2[index];
    }
}

int main()
{
    // 입력과 출력을 위한 메모리 할당
    float *input1, *input2, *output;
    cudaMallocManaged(&input1, N * M * M * sizeof(float));
    cudaMallocManaged(&input2, N * M * M * sizeof(float));
    cudaMallocManaged(&output, N * M * M * sizeof(float));

    // 입력 데이터 초기화
    for (int i = 0; i < N * M * M; ++i)
    {
        input1[i] = i;
        input2[i] = 2 * i;
    }

    dim3 threadsPerBlock(2, 2, 1);
    dim3 numBlocks((N + threadsPerBlock.x - 1) / threadsPerBlock.x,
                   (M + threadsPerBlock.y - 1) / threadsPerBlock.y,
                   (M + threadsPerBlock.z - 1) / threadsPerBlock.z);

    // 커널 실행
    addArrays<<<numBlocks, threadsPerBlock>>>(input1, input2, output);
    cudaDeviceSynchronize(); // 커널 실행 완료 대기

    // 결과 출력
    cout << "덧셈 결과:" << endl;
    for (int i = 0; i < N * M * M; ++i)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    // 메모리 해제
    cudaFree(input1);
    cudaFree(input2);
    cudaFree(output);

    return 0;
}
