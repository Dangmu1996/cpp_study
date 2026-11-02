#include <tuple>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    tuple t1(16, "Test"s, true);
    auto[i, str, b]= t1;
    cout << "Decomposed: i = "
        << i << ", str = \"" << str << "\", b = " << b << endl;
    

    int i_2 = 0;
    string str_2;
    bool b_2=false;
    cout << "Before: i_2 = " << i_2 << ", str_2 = \"" << str_2 << "\", b_2 = " << b_2 << endl;
    tie(i_2, str_2, b_2) = t1;
    cout << "After: i_2 = " << i_2 << ", str_2 = \"" << str_2 << "\", b_2 = " << b_2 << endl;

    return 0;
}