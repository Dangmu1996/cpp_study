#include <regex>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    regex r("(\\d{4})/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1])");
    while(true){
        cout<<"Enter a date (year/month/day) (q=quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
            break;
        
        // if(regex_match(str, r))
        //     cout<<" Valid date."<<endl;
        // else
        //     cout<<" Invalid date!"<<endl;
        smatch m;
        if(regex_match(str, m, r)){
            // int year = stoi(m[1]);
            // int month = stoi(m[2]);
            // int day = stoi(m[3]);
            cout <<" Valid date: Year="<<m[1].str()
                <<", month=" << m[2].str()
                <<", day="<<m[3].str()<<endl;
        }else{
            cout<<" Invalid date!"<<endl;
        }
    }

    return 0;
}
/*
/d{4}: 네 자리 숫자를 매치한다.
(?:0?[1-9]|1[0-2]) : 이 표현식은 운선순위를 명확하게 표현하기 위해 소괄호로 묶었다.
- 0?[1-9] : 1부터 9 사이의 숫자를 매치하며. 맨 앞에 0이 나올 수도 있다. 예를 들어 1, 2, 9, 03, 04 등은 매치한다. 반면 0, 10, 11등은 매치하지 않는다.
- 1[0=2]: 0, 10, 11등은 매치ㅏ지 않는다.
(?:0?[1-9]|[1-2][0-9]|3[0-1]) : 여기서도 캡처 그룹이 아닌 표현식을 소괄호로 묶고, 세 가지 부분 표현식 중 하나를 선택하도록 구성했다.
- 0?[1-9] :1부터 9 사이의 숫자를 매치하며. 맨 앞에 0이 나올 수도 있다. 예를 들어 1, 2, 9, 03, 04 등은 매치한다. 반면 0, 10, 11등은 매치하지 않는다.
- 3[0-1]: 30과 31만 매치한다.

*/