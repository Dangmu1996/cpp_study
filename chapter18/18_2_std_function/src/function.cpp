#include <functional>
#include <string>
#include <iostream>

//std::function<R(ArgTypes...)>
/*
다형성 함수 래퍼라고도 부르며, 함수 포인터로 사용할 수도 있고, 콜백함수를 구현하는 함수를 나타내는 매개변수로 사용할 수도 있다.
*/
using namespace std;

void func(int num, const string& str)
{
    cout<<"func("<<num<<", "<<str<<")"<<endl;
}

int main()
{
    function<void(int, const string&)> f1 = func;
    // auto f1 = func; -> 이렇게 하면 std::function이 아니라 함수 포인터로 판단한다.
    f1(1, "test");
    return 0;
}