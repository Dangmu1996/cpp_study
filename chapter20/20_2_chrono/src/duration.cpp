#include <chrono>
#include <ratio>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main()
{
    // 한 틱이 60초인 duration을 정의한다.
    duration<long, ratio<60>> d1(123);
    cout << d1.count() <<endl;

    // 한 틱이 1초고, 최대 duration을 할당 할 수 있는,
    // double 깂으로 표현하는 duration을 정의한다.
    duration<double> d2;
    d2 = d2.max();
    cout << d2.count() <<endl;

    // 두 가지 duration을 정의한다.
    // 하나는 한 틱이 1분이고, 다른 하나는 한 틱이 1초다.
    duration<long, ratio<60>> d3(10); // = 10분
    duration<long, ratio<1>> d4(14); // = 14초

    // 두 duration을 비교한다.
    if(d3>d4)
        cout<<"d3 > d4" <<endl;
    else
        cout<<"d3 < d4" <<endl;
    
    // d4를 1만큼 증가시켜 15초로 만든다.
    ++d4;

    // d4에 2를 곱해 30초로 만든다.
    d4 *= 2;

    // 두 duration을 더해 분 단위 duration 에 저장한다.
    duration<double, ratio<60>> d5 = d3 + d4;

    // 두 durationㅇ을 더해서 초 단위 duration에 저장한다.
    duration<long, ratio<1>> d6 =d3 + d4;
    cout << d3.count() << " minutes + " << d4.count() << " seconds ="
        << d5.count() << " minutes or"
        << d6.count() <<" seconds" <<endl;
    
    // 30초 duration을 생성한다.
    duration<long> d7(30);

    // 초 단위인 d7을 분 단위로 변환한다.
    duration<double, ratio<60>> d8(d7);
    cout<< d7.count() << " seconds = " <<d8.count() <<" minutes" << endl;

    auto myDuration = 42min; //42분

    return 0;
}