# install matplot with https://github.com/alandefreitas/matplotplusplus
# set with vcpkg
# sudo vcpkg install vcpkg install matplotplusplus

cmake_minimum_required(VERSION 3.10)
project(02_image_classification)

find_package(Matplot++ CONFIG REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    include
    ${Eigen3_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(knn ./src/knn.cc ./include/cifar_utils.hpp ./include/dangmu_utils.hpp)
target_link_libraries(knn PRIVATE Matplot++::cimg  Matplot++::matplot ${Eigen3_LIBRARIES} ${OpenCV_LIBRARIES})