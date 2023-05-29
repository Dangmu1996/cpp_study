#include "../lib/include/Grid.hpp"
#include "GameBoard.hpp"

int main(int argc, char **argv)
{
    Grid<int> myIntGrid;

    Grid<double> myDoubleGrid(11, 11);

    int x = myIntGrid.at(0,0).value_or(0);

    Grid<int> grid2(myIntGrid);
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;

    return 0;
}


/*함수 거에서 grid class 메서드 받아올때 다음과 같이 써야함
void processIntGrid(Grid<int> & grid)
{

}

그리고 쓰는게 귀찮다면 다음과 같이 쓸수도 잇음
using IntGrid = Grid<int>
void processIntGrid(IntGrid & grid)


동적 할당으로 사용하는 방법
auto myGridOnHeap = make_unique<Grid<Int>>(2,2);
myGridOnHeap -> at(0,0) = 10;
int x = myGridOnHeap.at(0, 0 ).value_or(0);
*/