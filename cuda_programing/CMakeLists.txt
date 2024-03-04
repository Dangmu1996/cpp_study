cmake_minimum_required(VERSION 3.10)
project(cuda_prgramming LANGUAGES CXX CUDA)

add_executable(01_hello_cuda ./src/01_hello_cuda.cu)
set_target_properties(01_hello_cuda PROPERTIES CUDA_ARCHITECTURES "80")

add_executable(02_kernels ./src/02_kernels.cu)
set_target_properties(02_kernels PROPERTIES CUDA_ARCHITECTURES "80")
