#include <functional>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// find_if()에 less 함수 객체를 사용할 수 없다.
// 어댑터 함수 객체는 함수 객체, 람다 표현식, 함수 포인터를 비롯한 모든 호출 기능 개체에 적용 할 수 있다.
// 함수를 하나로 합쳐서 원하는 기능을 구현 할 수 있다.

void func(int num, string_view str)
{
    cout<<"func("<<num<<", "<<str<<")"<<endl;
}// 바인더를 이용하면 호출 가능 개체의 매개변수를 일정한 값으로 묶어둘 수 있다.

void increment(int& value){++value;}

void overloaded(int num){}
void overloaded(float f){}

int main()
{
    // func()의 두번째 인수를 myString이란 고정된 값으로 바인딩하도록 bind()를 사용하는 방법을 보여주고 잇다. 결과는 f1()에 저장된다.
    // auto 키워드를 사용했는데, C++ 표준에 bind()의 리턴 타입이 명확히 정의돼 있지 않기 때문이다.
    // 특정한 값에 바인딩되지 않은 인수는 반드시(std::placeholders)네임스페이스에 정의된, _1, _2,_3등으로 지정해야 한다. f1()의 정의에서 _1은 func()를 호출 할 때
    // f1()의 첫 번째 인수가 들어갈 지점을 지정한다. 
    // 그러면 다음과 같이 f1()에 정수 타입 인수 하나만 지정해서 호출 할 수 있다.
    string myString = "abc";
    auto f1 = bind(func, placeholders::_1, myString);
    f1(16);

    auto f2 = bind(func, placeholders::_2, placeholders::_1);
    // 다음과 같이 하면 f2의 첫번째 인수는 func의 두번째 인수가 되고, f2()의 두번째 인수는 func()의 첫번째 인수가 된다.
    f2("Test", 32);

    int index =0;
    increment(index); // 이러면 1 증가 함.
    cout<<index<<endl;

    auto incr = bind(increment, index);
    incr(); // 이러면 증가하지 않음. index의 복제본에 대한 레퍼런스가  increment()함수의 첫번째 매개변수로 바인딩 되었기 때문
    cout<<index<<endl;

    auto incr_2 = bind(increment, ref(index));
    incr_2(); // 이러면 증가한다고 함.
    cout<<index<<endl;

    // 이러면 error 발생 auto f3 = bind(oberloaded, placeholders::_1)
    //부동 소수점 인수를 받는 오버로딩 함수의 매개변수를 바인딩 하고 싶다면 
    auto f4 = bind((void(*)(float))overloaded, placeholders::_1);

    vector<int> myVector{11, 22, 33, 44, 55, 112, 101, 115};
    auto endIter = end(myVector);
    auto it = find_if(begin(myVector), endIter, bind(greater_equal<>(), placeholders::_1, 100));
    if(it == endIter){
        cout<<"No perfect scores"<<endl;
    }else{
        cout<<"Found a \"perfect\" score of" << *it<<endl;
    }

    //당연히 람다 표현식으로 작성하면 훨씬 좋다.
    auto it2 = find_if(begin(myVector), endIter, [](int i){return i>=100;});



    return 0;
}