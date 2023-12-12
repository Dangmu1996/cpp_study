#include<functional>
#include<vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
// plus, minus, multiplies, divides, modulus
double geometricMean(const vector<int>& nums)
{
    double mult = accumulate(cbegin(nums), cend(nums), 1, multiplies<int>());
    // double mult = accumulate(cbegin(nums), cend(nums), 1, multiplies<>()); 이것도 가능 투명 연산자 형태의 펑터
    return pow(mult, 1.0 / nums.size());
}

int main()
{
    plus<int> myPlus;
    int res = myPlus(4,5);
    cout<<res<<endl;

    vector<int> nums{1,2,3};
    double result = accumulate(cbegin(nums), cend(nums), 1.1, multiplies<>());
    // 항상 투명 연산자 펑터를 사용하기 바란다고 나와있음. 이러면 1,2,3 정수 뿐 아니라 1.1과 같이 실수도 같이 계산함. 근데 int를 넣으면 경고 발생한다고 함.

    return 0;
}