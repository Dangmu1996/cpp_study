#include "Grid.hpp"
#include "MultiGrid.hpp"
#include <iostream>

using namespace std;

int main()
{
    OneDGrid<int> singleDGrid;
    OneDGrid<OneDGrid<int>> twoDGrid;
    OneDGrid<OneDGrid<OneDGrid<int>>> threeDGrid;
    singleDGrid[3] =5;
    twoDGrid[3][3] = 5;
    threeDGrid[3][3][3] =5;

    NDGrid<int, 3> my3DGrid;
    my3DGrid[2][1][2] = 5;
    my3DGrid[1][1][1] = 5;

    cout << my3DGrid[2][1][2] << endl;

    return 0;
}