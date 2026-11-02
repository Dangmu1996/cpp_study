#include <iostream>
#include <string>

using namespace std;

/*
boolalpha noboolalpha: boolapha를 지정하면 'false' 란 스트링 값을 부울 타입으로 false로 해석 하고, 나머지 스트림을 true로 해석한다. noboolalpha를 지정하면 0을 false, 나머지는 1로 차리한다
hex,oct,doc : 각각의 숫자를 16진수, 8진수, 10 진수로 읽도록 지정한다.
skipw, noskipw : skipw를 지정하면 토큰화할 때 공백을 건너뛰고, noskipws를 지정하면 공백을 하나의 토큰으로 취급한다.
ws: 스트림의 현재 위치부터 연달아 나온 공백 문자를 건너뛴다.
get_money : 스트림에서 일정한 형식으로 표현한 값을 읽는 매개변수 방식의 매니퓰레이터
get_time : 스트림에서 일정한 형식으로 표현된 시각 정보를 읽는 매개변수 방식의 매니퓰레이터
quoted : 인용부호(따움표)로 묶은 스트링을 읽는 매니퓰레이터로서 인수를 받는디ㅣ. 이스케이프 문자로 입력된 따움표는 스트링에 포함된다.
*/

int main(int argc, char ** argv)
{
    cin.imbue(locale(""));
    int i;
    cin >>i; // English일 때, 1,000을 입력하면 1000을 읽음

    cout<<i;

    return 0;
}