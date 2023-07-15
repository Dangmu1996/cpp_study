check python version
sudo apt install python3-pip

get the code from https://github.com/lava/matplotlib-cpp

mv the matplotlibcpp.h to /usr/local/include

g++ main.cpp -I/usr/include/python3.10 -lpython3.10 -o main