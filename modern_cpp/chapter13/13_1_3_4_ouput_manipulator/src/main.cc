#include <iostream>
#include <ios>
#include <iomanip>
#include <cstdio>

using namespace std;
// boolalpha & noboolalhpa 스트림에 bool 값을 true나 false 로 출력하지 않고 1이나 0으로 출력하도록 설정한다.
// hex, oct, dec 각각 숫자를 16진수 8진수 10진수로 출력한다.
// setprecision 분숫값을 표현할 때 정용할 소수점 자리수를 지정한다. 이를 위해 자리수를 표현하는 인수를 받는다.
// setw 숫자 데이터를 출력할 필드의 너비를 지정한다.
// setfill 지정된 너비보다 숫자가 작을 때 빈 공간을 채울 문자를 지정한다.
// showpoint & noshowpoint 소수점 아래의 수가 없는 부동소수점을 스트림에서 표현 할 때 소수점 표시 여부를 설정한다.
// put_money 스트림에서 화폐 금액을 일정한 형식에 맞게 표현할 때 사용하는 매니퓰레이터로서 인수를 받는다.
// put_time 스트림에서 시간을일정한 형식에 맞게 표현 할 때 사용하는 매니퓰레이터로서 인수를 받는다
// quoted 지정한 스티링을 인용부호 (따움표)로 감싸고 스트링 안에 있던 인용부호를 이스케이프 문자로 변환한다.

int main(int argc, char ** argv)
{    
    //bool 값
    bool myBool = true;
    cout << "This is the default" << myBool <<endl;
    cout << "This should be true" << boolalpha <<endl;
    cout << "This should be 1" << noboolalpha <<endl;

    //"%6d"와 같은 효과를 스트림에 적용하는 방법
    int i = 123;
    printf("This should be '123: %6d\n", i);
    cout<< " This should be '123: " << setw(6)<<i<<endl;

    //"%6d"와 같은 효과를 스트림에 적용하는 방법
    printf("This should be '00123' : %06d\n", i);
    cout << "This should be '000123' : " <<setfill('0')<<setw(6)<<i<<endl;

    // *로 채우기
    cout<<"This should be '***123': "<<setfill('*')<<setw(6)<<endl;

    //빈칸 채우기 문자 리셋
    cout<<setfill(' ');

    //부동소수점수
    double dbl = 1.452;
    double dbl2 = 5;
    cout<<"This should be ' 5' : "<< setw(2) << noshowpoint << dbl2 << endl;
    cout<<"This should be @@1.452: " <<setw(7) <<setfill('@')<<dbl<<endl;
    //빈칸 채우기 문자 리셋
    cout<<setfill(' ');

    //cout에서 숫자 포맷을 지역(국가)에 맞게 설정한다
    cout.imbue(locale(""));

    //현재 지역에 맞게 숫자를 표현
    cout<<"This is 1234567 formatted according to your location: " <<1234567<<endl;
    
    //화패 금액을 표현
    cout<<"This should be a monetary value of 120000, "
        <<"formatted according to your location: "
        <<put_money("120000")<<endl;
    
    //날짜와 시간
    cout<<"This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
        <<quoted("Quoted string with \"embedded quotes\".")<<endl;

    return 0;
}