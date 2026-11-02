#include <iostream>

using namespace std;

int main()
{
    // 문자가 차지하는 공간을 결정했다면 아스키 코드처럼 각 문자를 코드 포인트라 부르는 숫자 형태로 표현 할 수 있다.
    // 한 문자를 1~4개의 8비트로 인코딩하는 UTF-8, 한 문자를 1~2개의 16비트값으로 인코딩 하는 UTF-16, 유니코드 문자를 정확히 32비트로 인코딩하는 UTF=32
    // char : 8비트값을 담는다. 주로 아스키 문자나 한 문자를 1~4개의 char로 인코딩 하는 UTF-8 방식의 유니코드 문자를 지정하는데 사용된다.
    // char16_t : 16비트 값을 담는다. 이 타입은 문자 하나를 1~2개의 chat16_t로 인코딩하는 UTF-16 방식의 유니코드 문자를 지정하는 기본 타입으로 사용된다.
    // chat32_t : 최소 32비트값을 담는다. 이 타입은 UTF-32로 인코딩된 유니코드 문자를 하나의 char32_t로 저장하는데 사용된다.
    // wchar_t: 와이드 문자를 표현하는 타입으로, 구체적인 크기와 인코딩 방식은 컴파일러 마다 다른다.

    // 스트링 러터럴 앞에 특정한 접두어를 붙여서 타입을 지정할 수 있다. c++에서 제공하는 스트링 접두어는 다음과 같다.
    // u8 : UTF-8 인코딩을 적용한 char 스트링
    // u : char16_t 스트링 리터럴을 표현하며, 컴파일러에 __STDC_UTF_16__이 정의돼 있으면 UTF-16을 적용한다.
    // U : char32_t 스트링 리터럴을 표현하며, 컴파일러에 __STDC_UTF_32__가 정의돼 있으면 UTF=32를 적용한다.
    // L : wchar_t 스트링 리터럴을 표현하며, 인코딩 방식은 컴파일러마다 다르다.
    // 이러한 스트링 리터럴은 모두 일반 스트링 리터럴 접두어인 R고ㅓㅏ 조합할 수 있다.
    const char* s1 = u8R"(Raw UTF-8 encoded string literal)";
    const wchar_t* s2 = LR"(Raw wide string literal)";
    const char16_t* s3 = uR"(Raw char16_t string literal)";
    const char32_t* s4 = UR"(Raw char32_t stiring literal)";

    cout<<s1<<endl;
    wcout<<s2<<endl;
    
    //파이알제곱 표현
    const char* formula = u8"\u03C0 r\u00B2";
    cout<<formula<<endl;

    // 문자 리터럴 앞에도 접두어를 붙여서 타입을 구체적으로 지정할 수 있다.
    // C++는 문자 리터럴에 대해, u, U, L 뿐만 아니라 C++17 부터 u8 접두어도 지원한다.
    // u'a', U'a', L'a', u8'a'

    // C++는 std::string 클래스 외에  wstring, u16string, u32string 도 제공한다.
    // using string = basic_string<char>;
    // using wstring = basing_string<wchar_t>;
    // using u16string = basic_string<char16_t>;
    // using u32string = basic_string<char32_t>;

    return 0;
}