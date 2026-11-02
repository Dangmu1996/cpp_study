#include "SpreadsheetCell.hpp"
#include "Pointer.hpp"
#include <iostream>

void process(Pointer<SpreadsheetCell>& p)
{
    if(p!=nullptr)
        std::cout<<"not nullptr"<<std::endl;
    if(p!=NULL)
        std::cout<<"not NULL"<<std::endl;
    if(p)
        std::cout<<"not nullptr"<<std::endl;
    if(!p)
        std::cout<<"nullptr"<<std::endl;
    
}


int main()
{
    // SpreadsheetCell cell(1.23);
    // double d1 = cell;

    // std::string str = cell;
    SpreadsheetCell cell = 6.6;
    std::string str = cell;
    double d1 = static_cast<double>(cell);
    // double d2 = static_cast<double>(cell);

    Pointer<SpreadsheetCell> smartCell(nullptr);
    process(smartCell);
    std::cout<<std::endl;

    Pointer<SpreadsheetCell> anotherSmartCell(new SpreadsheetCell(5.0));
    // int i = anotherSmartCell;
    process(anotherSmartCell);

    return 0;
}