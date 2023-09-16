#include "FunctionObject.hpp"

// 오버로딩한 함수 호출 연산자의 구현 코드
int FunctionObject::operator()(int param)
{
    return doSquare(param);
}

//일반 메서드의 구현 코드
int FunctionObject::doSquare(int param)
{
    return param*param;
}