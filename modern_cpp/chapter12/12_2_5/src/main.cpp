#include "../lib/include/Grid.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    /*
    Grid<int, 10, 10> myGrid;
    Grid<int, 10, 10> anotherGrid;
    myGrid.at(2,3) =42;
    anotherGrid = myGrid;
    cout<<anotherGrid.at(2, 3).value_or(0);
*/
    //타입 매개변수 디폴트값 저장한 이후
    Grid<> myIntGrid;
    Grid<int> myGrid;
    Grid<int , 5> anotherGrid;
    Grid<int, 5, 5> aFourGrid;
    return 0;
}


//이러면 안됨
//size_t height = 10;
//Grid<int ,10 ,height> testGrid ;

//이러면 됨
//cosnt size_t height = 10;
//Grid<int, 10, height> testGrid;

//이래도 됨
//constexpr size_t getHeight(){return 10;}
//Grid<double, 2, getHeight()>myDoubleGrid;