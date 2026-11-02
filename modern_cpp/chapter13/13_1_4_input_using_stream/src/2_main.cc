#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv)
{
    cout<<"Enter number on seperate lines to add."
        << "Use  control+D to finish (Control+Z in windows)."<<endl;
    int sum=0;

    if(!cin.good())
    {
        cerr<<"Standard input is in a bad state!"<<endl;
        return 0;
    }

    int number;
    while (!cin.bad())
    {
        cin >>number;
        if(cin.good())
        {
            sum+=number;
        }
        else if (cin.eof())
        {
            break; //파일 끝에 도달했다.
        }
        else if (cin.fail())
        {
            //문제 발생
            cin.clear(); //에러 상태를 제거한다.
            string badToken;
            cin>>badToken; //잘못된 입력 값을 가져온다.
            cerr<<"WARNING : bad input encountered: "<<badToken<<endl;

        }
    }
    cout <<"The sum is " <<sum<<endl;

    return 0;

}