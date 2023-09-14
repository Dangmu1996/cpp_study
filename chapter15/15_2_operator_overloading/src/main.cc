#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    SpreadsheetCell c1(4);
    SpreadsheetCell c3 = -c1;

    cout<<c1.getValue()<<endl;
    cout<<c3.getValue()<<endl;

    SpreadsheetCell c2(4);
    SpreadsheetCell c4(4);

    c2++;
    ++c2;
    // cout<<c2++.getValue()<<endl;
    // cout<<++c4.getValue()<<endl;
    return 0;
}