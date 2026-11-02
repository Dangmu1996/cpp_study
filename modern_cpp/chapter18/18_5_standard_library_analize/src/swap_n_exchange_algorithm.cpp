#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int a = 11;
    int b = 22;
    cout << "Before swap(): a = " << a << ", b = " << b <<endl;
    swap(a,b);
    cout << "After swap(): a = " << a << ", b = " << b <<endl;   


    int c = 11;
    int d = 22;
    cout << "Before exchange(): c = " << c <<", d = "<< d <<endl;
    int returnedValue = exchange(c, d);
    cout<< "After exchang(): c = " << c <<", d = "<<d<<endl;
    cout << "exchange() returned: "<<returnedValue << endl;


    return 0;
}