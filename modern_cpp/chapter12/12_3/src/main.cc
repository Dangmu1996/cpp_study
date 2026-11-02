#include <cstdlib>
#include <iostream>
#include "SpreadsheetCell.hpp"

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
    for(size_t i =0; i<size; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

int main(int argc, char ** argv)
{
    int myInt =3, intArray[] = {1, 2, 3, 4};
    const size_t sizeIntArray  = std::size(intArray);

    size_t res;
    res = Find(myInt, intArray, sizeIntArray); // 타입 추론을 통해서 int로 알아냄
    res = Find<int>(myInt, intArray, sizeIntArray); //Find<int>를 명시적으로 호출
    if(res!=NOT_FOUND)
        std::cout<<res<<std::endl;
    else
        std::cout<<"Not Found"<<std::endl;

    double myDouble = 5.6, doubleArray[] = {1.2, 3.4, 5.7, 7.5};
    const size_t sizeDoubleArray = std::size(doubleArray);

    res=Find(myDouble, doubleArray, sizeDoubleArray); // 알아서 double이라고
    res=Find<double>(myDouble, doubleArray, sizeDoubleArray); //명시적으로 적음
    if(res!=NOT_FOUND)
        std::cout<<res<<std::endl;
    else
        std::cout<<"Not Found"<<std::endl;

    /*res = Find(myInt, doubleArray, sizeDouble); 같은 경우에는 컴파일 에러가 발생 타입이 서로 다르기 때문임, my Int가 있더라고 명시적으로 Find<double>을 호출함*/
    res=Find<double>(myInt, doubleArray, sizeDoubleArray);

    SpreadsheetCell cell1(10), cellArray[]={SpreadsheetCell(4), SpreadsheetCell(10)};
    const size_t sizeCellArray = std::size(cellArray);

    res = Find(cell1, cellArray, sizeCellArray);
    res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray);

    return 0;
}