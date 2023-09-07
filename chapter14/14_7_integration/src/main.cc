#include "GameBoard.hpp"
#include <exception>
#include <iostream>

int main()
{  
    try{
        GameBoard b_1(5, 5);
        // GameBoard b_2;

        // b_1 = b_2;
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    
    return 0;
}