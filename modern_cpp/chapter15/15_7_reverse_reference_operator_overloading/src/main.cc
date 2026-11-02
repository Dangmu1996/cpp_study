#include "SpreadsheetCell.hpp"
#include "Pointer.hpp"
#include <iostream>

using namespace std;

int main()
{
    Pointer<int> smartInt(new int);
    *smartInt = 5; //스마트 포인터를 역참조 한다.
    cout<<*smartInt<<endl;    

    Pointer<SpreadsheetCell> smartCell(new SpreadsheetCell);
    smartCell->setValue(5); //smartCel을 역참조 해서 set 메서드라는 멤버를 선택한다.
    cout<<smartCell->getValue()<<endl;
    return 0;
}