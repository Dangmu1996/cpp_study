#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    // 문화적 배경에 따라 그룹으로 묶는 방식을 로케일, 로케일은 날짜 포맷, 시간 포맷, 숫자 포맷 등으로 구성되는데, 이러한 요소를 패싯이라 부른다.
    wcout.imbue(locale(""));
    wcout<<32767<<endl;

    wcout.imbue(locale("C"));
    wcout<<32767<<endl;

    wcout.imbue(locale("ko_KR.UTF-8")); // "en_US" for POSIX
    wcout<<32767<<endl;

    // 현재 locale이 loc 객체에 저장됨 그리고 이게 en_us인지 검사하는 것
    locale loc("");
    if(loc.name().find("en_US") == string::npos &&
        loc.name().find("en-US") == string::npos){
            wcout<<L"Welcome non-U.S. English Speaker!"<<endl;
        }else{
            wcout<<L"Welcome U.S. English speaker!"<<endl;
        }

    bool result = isupper('A', locale(""));
    if(result){
        cout<<"this is upper"<<endl;
    }

    locale locUSEng("en_US.UTF-8");
    locale locKorean("ko_KR.UTF-8");

    wstring dollars = use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol();
    wstring won = use_facet<moneypunct<wchar_t>>(locKorean).curr_symbol();

    wcout << L"In the US, the currency symbol is "<<dollars<<endl;
    wcout << L"In South Korea, the currency symbol is "<<won<<endl;
    return 0;
}