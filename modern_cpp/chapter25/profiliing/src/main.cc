// #include "FirstNameDB.hpp"
#include "SecondNameDB.hpp"
#include <iostream>

using namespace std;

int main(void)
{
    NameDB boys("../data/boys_long.txt");
    cout << boys.getNameRank("Daniel") << endl;
    cout << boys.getNameRank("Jacob") << endl;
    cout << boys.getNameRank("William")<<endl;
    return 0;
}