#include <numeric>
#include <vector>

using namespace std;

// logical_not(operator!), logical_and(operator&&), logical_or(operator||) 이렇게 함수 포인터로 사용하는 이유는 펑터로 사용하기 위함임.
// 비트 연산 함수 객체, bit_and(operator&), bit_or(operator|), bit_xor(operator^), bit_not(operator~)

bool allTrue(const vector<bool>& flags)
{
    return accumulate(begin(flags), end(flags), true, logical_and<>());
}

bool anyTrue(const vector<bool>& flags)
{
    return accumulate(begin(flags), end(flags), false, logical_or<>());
}

int main()
{



    return 0;
}