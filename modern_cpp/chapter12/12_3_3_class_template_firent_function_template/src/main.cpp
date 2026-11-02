#include "../lib/include/Grid.hpp"
#include <iostream>
#include <cstdio>

int main(int argc, char** argv)
{
    Grid<int> a(8,8), b(8,8);
    a.at(1, 1) = 1;
    b.at(1, 1) = 2;

    Grid<int> c = a+b;

    // auto temp = c.at(1,1);
    
    // std::cout<<temp<<std::endl;
    // std::ostream(temp);
    // printf(int(temp));

    return 0;
}