cmake_minimum_required(VERSION 3.22.1)
project(cuda_prgramming LANGUAGES CXX CUDA)

add_executable(01_hello_cuda ./src/01_hello_cuda.cu)
set_target_properties(01_hello_cuda PROPERTIES CUDA_ARCHITECTURES "86")

add_executable(02_kernels ./src/02_kernels.cu)
set_target_properties(02_kernels PROPERTIES CUDA_ARCHITECTURES "86")

add_executable(03_thread_hierachy ./src/03_thread_hierachy.cu)
set_target_properties(03_thread_hierachy PROPERTIES CUDA_ARCHITECTURES "86")

add_executable(04_block_cluster ./src/04_block_cluster.cu)
set_target_properties(04_block_cluster PROPERTIES CUDA_ARCHITECTURES "86")