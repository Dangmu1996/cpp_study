// #include "string_grid.hpp"
#include "ptr_grid.hpp"
#include <iostream>

using namespace std;

int main()
{
    // Grid<int, 2, 2> myIntGrid; // 원본 Grid를 사용한다.
    // Grid<const char*, 2, 2> myStringGrid; // 부분 특수화를 적용한다.
    // Grid<2, 3> test; 타입을 지정하지 않으면 컴파일 에러 발생

    Grid<int> myIntGrid; // 특수화 하지 않은 Grid를 사용한다.
    Grid<int*> psGrid(2, 2); // 포인터 타입에 대해 부분 특수화한 버전을 사용한다.

    psGrid.at(0, 0) = make_unique<int>(1);
    psGrid.at(0, 1) = make_unique<int>(2);
    psGrid.at(1, 0) = make_unique<int>(3);

    Grid<int*> psGrid2(psGrid);
    Grid<int*> psGrid3;
    psGrid3 = psGrid2;

    auto& element = psGrid2.at(1, 0);
    if(element){
        cout << *element << endl;
        *element = 6;
    }

    cout << *psGrid.at(1,0)<<endl; //psGrid는 수정되지 않는다.
    cout<< *psGrid2.at(1, 0)<<endl; //psGrid2는 수정된다.

    return 0;
}