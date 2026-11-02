#include "Array.hpp"
#include <iostream>

void printArray(const Array<int>& arr)
{
    for(size_t i=0; i<arr.getSize(); i++)
    {
        std::cout<<arr[i]<<" "; //arr이 const 객체이므로 const operator[]를 호출한다.
    }
    std::cout<<std::endl;
}

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    Array<int> mArray;
    for(size_t i =0; i< 10; i++)
    {
        mArray.setElementAt(i , 100);
    }
    for(size_t i=0; i<10; i++)
    {
        std::cout<<mArray.getElementAt(i)<< "  ";
    }

    printArray(mArray);

    Array<int> mArray2;
    for(size_t i=0; i<10; i++)
    {
        mArray2[i] = 100;
    }

    for(size_t i =0; i<10; i++)
    {
        std::cout<<mArray2[i]<<" ";
    }

    return 0;
}