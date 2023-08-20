#include <iostream>
#include <string>

using namespace std;

void getReservationData()
{
    string guestName;
    int partySize;
    cout<<"Name and number of guests: ";
    cin >> guestName >> partySize;
    cout <<"Thank you, "<<guestName<<"."<<endl;
    if(partySize>10)
    {
        cout<<"An extra gratuity will apply."<<endl;
    }
}


int main(int argc, char ** argv)
{
    // >> 연산자의 기본 설정은 공백을 기준으로 입력된 값을 토큰 단위로 나눈다. 따라서  hello there을 입력하면 hello 만 입력됨
    string userInput;
    cin>>userInput;
    cout<<"User input was " << userInput <<endl;

    int userInput2;
    cin>>userInput2;
    cout<<"User input was "<<userInput2 <<endl;

    getReservationData();

    return 0;
}