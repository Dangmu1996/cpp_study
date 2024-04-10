cmake_minimum_required(VERSION 3.10)

project(cuda_image_acceleration)

# CUDA 및 OpenCV
find_package(CUDA 11 REQUIRED)
enable_language(CUDA)
find_package(OpenCV REQUIRED)

# CUDA 컴파일 옵션을
set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_ARCHITECTURES 86)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} -gencode arch=compute_86,code=sm_86)

# CUDA 및 C++ 소스 파일 설정
set(CUDA_SOURCES src/gaussian_blur.cu)
set(CPP_SOURCES src/main.cpp)

# CUDA 소스 파일 컴파일 object 파일 생성
cuda_add_library(gaussian_blur_cuda ${CUDA_SOURCES})

# main 프로그램에 object 파일을 추가하여 링크
add_executable(main ${CPP_SOURCES})

# include 디렉토리를 설정
include_directories(include/)
include_directories(${OpenCV_INCLUDE_DIRS})

# CUDA object 파일과 OpenCV 라이브러리를 링크
target_link_libraries(main gaussian_blur_cuda ${OpenCV_LIBS})
