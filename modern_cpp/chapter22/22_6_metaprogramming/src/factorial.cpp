#include <iostream>

using namespace std;

template <unsigned char f>
class Factorial
{
public:
    static const unsigned long long val = (f*Factorial<f-1>::val);
};

template<>
class Factorial<0>
{
public:
    static const unsigned long long val = 1;
};

int main()
{
    cout << Factorial<6>::val << endl; // 이러면 팩토리얼 계산을 컴파일러 시간에 함.
    return 0;
}