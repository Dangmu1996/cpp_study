#include <iterator>
#include <iostream>
#include <memory_resource>
#include <numeric>

using namespace std;
using namespace std::pmr;

int main()
{
    cout << "Enter numbers seperated by white space."<<endl;
    cout << "Press Ctrl+D Followed by Enter to stop" <<endl;
    istream_iterator<int> numbersIter(cin);
    istream_iterator<int> endIter;
    int sum = accumulate(numbersIter, endIter, 0);
    cout << "Sum: " << sum << endl;

    return 0;
}