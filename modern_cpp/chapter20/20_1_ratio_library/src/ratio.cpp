#include <ratio>
#include <iostream>

using namespace std;

int main()
{
    // ratio 라이브러리를 이용하면 유한 유리수를 컴파일 시간에 정확히 표현 할 수 있다.
    using r1 = ratio<1,60>;
    intmax_t num = r1::num;
    intmax_t den = r1::den;
    cout<<num <<", "<< den <<endl;

    // 유리수의 덧셈, 뺄셈, 곱셈, 나눗셈을 지웒나다. 컴파일 시간에 초리되어서 표준 산술 연산을 적용 할 수 없어 타입 엘리어스를 이용한 특수 템플릿으로 처리해야 한다.
    using r2 = ratio<1,30>;
    using result = ratio_add<r1, r2>::type;
    intmax_t num_result = result::num;
    intmax_t den_result = result::den;
    cout<<num_result<<", "<<den_result<<endl;

    // 두 유리수를 비교한다.
    using res = ratio_less<r2, r1>;
    cout << boolalpha << res::value << endl;

    return 0;
}