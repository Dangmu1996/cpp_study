#include <sstream>
#include <iostream>
#include <string>

using namespace std;

/*
사용자로부터 받은 단어들을 탭 문자로 구분해서 ostringstream에 쓴다.
다 쓰고 나면 str() 메서드를 이용하여 스트림 전체를 string 객체로 변환한 뒤 콘솔에 쓴다.
입력값은 'done'이란 단어를 입력할 때까지 토큰 단위로 입력받거나, 유닉스라면 ctrl+D를, 윈도우라면 Ctrl+z를 입력하여 입력스트림을
닫기 전까지 입력 받음
*/
int main(int argc, char ** argv)
{
    cout<<"Enter token. Control+D(Unix) or Control+Z (Windows) to end"<<endl;
    ostringstream outStream;

    while(cin)
    {
        string nextToken;
        cout<< "Next token: ";
        cin>>nextToken;
        if(!cin || nextToken == "done")
            break;
        outStream << nextToken <<"\t";
    }
    cout<<"The end result is: "<<outStream.str();

    return 0;
}
