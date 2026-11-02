#include <tuple>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    tuple<int,string, bool> t1(16,"Test", true);
    tuple<double, string> t2(3.14,"string 2");
    auto t3 = tuple_cat(t1, t2); // t3 tuple<int, string, bool, double, string>
    return 0;
}