#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec(10);
    int value = 1;
    generate(begin(vec), end(vec), [&value]{ value *= 2; return value;});
    for(const auto & i : vec){
        cout << i << " ";
    }

    return 0;
}