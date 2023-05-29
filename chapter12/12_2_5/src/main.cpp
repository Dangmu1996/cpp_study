#include "../lib/include/Grid.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Grid<int, 10, 10> myGrid;
    Grid<int, 10, 10> anotherGrid;
    myGrid.at(2,3) =42;
    anotherGrid = myGrid;
    cout<<anotherGrid.at(2, 3).value_or(0);
    return 0;
}