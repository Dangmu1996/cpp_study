#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

int main()
{
    double pi = 3.1415;
    auto myLambda = [myCapture = "Pi: ", pi]{cout<<myCapture<<pi;};

    // 람다 캡처 변수는 std::move()를 비롯한 모든 종류의 표현식으로 초리화 할 수 있다. unique_ptr처럼 복제할 수 없고 이동만 가능한 객체를 다룰 때 이 점을 반드시 명심해야 한다.
    // 기본적으로 값으로 캡처하면 복제 방식이 적용된다. 그래서 unique_ptr를 람다 표현식에 값으로 캡처 할 수 없다. 하지만 람다 표현식을 사용하면 다음과 같이 이동 방식으로 복제할 수 잇다.
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda2 = [p = std::move(myPtr)]{cout<<*p;};

    myLambda();
    myLambda2();

    return 0;
}