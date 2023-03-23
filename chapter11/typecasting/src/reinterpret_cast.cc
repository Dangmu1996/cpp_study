#include <iostream>

using namespace std;

class X{};
class Y{};

int main()
{
    X x;
    Y y;
    X* xp=&x;
    Y* yp=&y;
    //서로 관련 없는 것들 casting은  reinterpret_cast
    xp=reinterpret_cast<X*>(yp);
    //포인터를 void*로 변환할 때는 캐스팅하지 않아도 된다.
    void* p =xp;
    //변환된 void*를 다시 원래 포인터로 복원할 때는 reinterpret_cast()를 써야 한다.
    xp=reinterpret_cast<X*>(p);
    //t서로 관련없는 타입의 레퍼런스 끼리 변환할 때 reinterpret_cast()를 써야함
    X& xr =x;
    Y& yr = reinterpret_cast<Y&>(x);
    return 0;
}