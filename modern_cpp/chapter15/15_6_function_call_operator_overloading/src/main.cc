#include "FunctionObject.hpp"

int main()
{
    int x = 3, xSquared, xSquaredAgain;
    FunctionObject square;
    xSquared = square(x); // 함수 호출 연산자를 호출한다.
    xSquaredAgain = square.doSquare(x); // 일반 메서드를 호출한다.

    return 0;
}