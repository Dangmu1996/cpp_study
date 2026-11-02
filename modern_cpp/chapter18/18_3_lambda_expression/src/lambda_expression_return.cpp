#include <functional>
#include <iostream>

using namespace std;

function<int(void)> multiplyBy2Lambda(int x)
{
    return [x]{return 2*x;};//이렇게 하면 function이 펑터로도 쓰이니까 람다식을 리턴 값으로 설정 할 수 있다.
}

//좀더 세련되게 ? 표현 가능
/*
auto multiplyBy2Lambda(int x)
{
    return [x]{return 2*x;};
}
*/

// 이렇게 리턴에서 x를 레퍼런스로 캡처하면 문제가 발ㅅ애한다. 람다 표현식은 대부분 이 함수가 끝난 뒤에 사용된다.
/*
auto multiplyBy2Lambda(int x)
{
    return [&x]{return 2*x;};// 버그 발생
}
*/

int main()
{
    function<int(void)> fn = multiplyBy2Lambda(5);
    cout<<fn()<<endl;

    return 0;
}