#include "../lib/include/GridString.hpp"

int main(int argc, char** argv)
{
    Grid<int> myIntGrid;
    Grid<const char*> stringGrid1(2,2);

    const char* dummy = "dummy";
    stringGrid1.at(0,0)="hello";
    stringGrid1.at(0,1)=dummy;
    stringGrid1.at(1,0)=dummy;
    stringGrid1.at(1,1)="there";
    

    Grid<const char*> stringGrid2(stringGrid1);
    return 0;
}