#include <iostream>


// 일단 현지화 할 수 있도록 소스 코드를 구성하려면 스트링 리터럴을 조합하는 방식으로 문장을 만들면 안된다.
// ex) cout << "Read" << n << " bytes"<<endl;
// 이걸 네덜란드어처럼 하면 어순이 달라 현지화 하기 힘들다.
// cout << n <<" bytes gelezen" << endl;
// 이 스트링을 제대로 현지화 할 수 있게 구성하려면 다음과 같이 구성해야 한다.
// cout << Format(IDS_TRANSFERRED, n) << endl;

using namespace std;

int main()
{
    // 한국어나 아랍어처럼 아스키 문자를 사용하지 않는 언어는 c++ 에서 wchar_t 타입으로 표현하면 된다.
    // 하지만  c++ 표준은 wchar_t의 크기를 지정하지 않는다. 어떤 컴파일러는 16비트를 사용하고, 다른 컴파일러는 32비트로 처리한다.
    // 크로스 플랫폼을 지원하도록 코드를 작성하면 wchar_t의 크기가 일정하다고 가정하면 위험하다.

    // 스트링이나 문자 리터럴을 wchar_t 타입으로 지정하려면 리터럴 앞에 L을 붙이면 된다. 그러면 와이드 문자 인코딩을 적용한다.
    wchar_t myWideCharacter = L'm';
    wcout << L"I am a wide-character string literal."<<endl;

    return 0;
}