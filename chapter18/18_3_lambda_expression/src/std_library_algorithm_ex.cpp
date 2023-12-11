#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,5,6,7,8,9};
    int value = 3;
    // count if는 원소의 수를 센다. 이때 조건을 람다 표현식으로 지정한다. 그래서 스코프에 있는 value란 변수를 값으로 캡처한다.
    int cnt = count_if(cbegin(vec), cend(vec), [value](int i){return i > value;});

    cout<<"Found "<<cnt<<" values > "<<value<<endl;

    return 0;
}