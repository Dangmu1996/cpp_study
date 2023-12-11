#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    auto basicLambda = []{cout << "Hello from Lambda"<<endl;};
    //[]는 람다 선언자, 람다 소개자
    basicLambda();

    auto parametersLambda =
        [](int value){cout<<"The value is "<<value<<endl;};
    
    parametersLambda(42);

    auto returningLambda = [](int a, int b){return a+b;};
    int sum = returningLambda(11, 22);

    // 다음과 같이 작성하면 자신이 속한 스코프에 있는 변수에 접근 할 수 있다.
    // 대괄호 부분을 캡처 블록이라고 부른다.
    double data = 1.23;
    auto capturingLambda =[data]{cout<<"Data = "<<data<<endl;};

    /*
    컴파일러는 람다 표현식을 이름 없는 펑터로 변환한다.
    다음과 같이 작성하면 펑터는 const 데이터 멤버를 갖게 된다.
    const double data = 1.23;
    auto capturingLambda = [data]{cout<<"Data = "<<data<<endl;};

    펑터마다 함수 호출 연산자인 operator()가 구현돼 있다. 람다 표현식의 경우 이 연산자는 기본적으로 const로 설정된다. 따라서 non-const 변수를 람다 표현식에 값으로 캡처해도
    람다 표현식 안에서 이 값의 복제본을 수정할 수 없다. 다음과 같이 람다 표현식을 mutable로 지정하면 함수 호출 연산자를 non-const로 만들 수 있다.
    double data = 1.23;
    auto capturingLambda =
        [data]()mutable{data *= 2; cout<<"Data = " << data << endl;};
    
    
    변수 이름 앞에 &를 붙이면 레퍼런스로 캡처한다. 다음 코드는 data 변수를 레퍼런스로 캡처해서 람다 표현식 안에서 data를 직접 수정하는 예를 보여준다.
    double data =1.23;
    auto capturingLambda = [&data]{data*=2;};

    [=]: 스코프에 있는 변수를 모두 값으로 캡처한다.
    [&]: 스코프에 있는 값을 모두 레퍼런스로 캡처한다.

    [&x] : 변수 x만 레퍼런스로 캡처한다.
    [x]: 변수 xaks 값으로 캡처한다.
    [=, &x. &y]: x와 y는 레퍼런스로 캡처하고, 나머지는 값으로 캡처한다.
    [&, x]: x만 값으로 캡처하고, 나머지는 레퍼런스로 캡처한다.
    [&x, &x]: 식별자(변수 이름 등)를 중복해서 지정했으므로 잘못된 표현이다.
    [this]: 현재 객체를 캡처한다. 람다 표현식의 본문 안에서 이 객체에 접근할 때this->를 붙이지 않아도 된다.
    [*this]: 현재 객체의 복제본을 캡처한다. 람다 표현식을 실행하는 시점에 객체가 살아 있지 않을 때 유용하다.
    
    람다 표현식의 문법을 정리하면 다음과 같다.
    [캡처 블록](매개변수) mutable constexpr
        noexcept 속성
        -> 리턴_타입 { 본문 }
    캡처 블록: 스코프에 있는 변수를 캡처하는 방식을 지정하고, 람다 표현식의 본문에서 그 변수에 접근 할 수 있게 만든다.
    매개변수(생략 가능): 람다 표현식에 대한 매개변수 목록, 매개변수를 받지 않고 mutable, const 표현식, noexcept 지정자, 속성, 리턴 타입을 지정하지 않는다면 생략해도 된다.
    매개변수 목록을 지정하는 방식은 일반 함수와 같다.
    mutable(생략 가능): 람다 표현식을 mutable로 지정한다. 자세한 사항은 앞에 나온 예제를 참조한다.
    constexpr(생략 가능): 람다 표현식을 const로 지정한다. 그러면 컴파일 시간에 평가된다. 명시적으로 지정하지 않더라도 람다 표현식이 일정한 요건을 충족하면 내부적으로 const로 처리된다.
    자세한 내용은 생략
    속서(생략 가능): 람다 표현식에 대한 속성을 지정한다.
    리턴_타입(생략 가능): 리턴 값의 타입을 지정한다. 생략하면 컴파일러가 추론한다. 방법은 일반 함수의 리턴 타입을 추론 할 때와 같다.
    */


    return 0;
}