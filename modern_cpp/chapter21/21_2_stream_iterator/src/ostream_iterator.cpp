#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int main()
{
    vector<int> myVector(10);
    iota(begin(myVector), end(myVector), 1); // 벡터를 1, 2, 3 ... 10으로 채운다

    // 벡터에 담긴 내용을 콘솔에 출력한다.
    copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout," "));

    return 0;
}