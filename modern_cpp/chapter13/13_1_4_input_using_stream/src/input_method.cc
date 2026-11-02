#include <iostream>
#include <string>

using namespace std;

string readName(istream& stream) // 매케변수 타입은 non-const istream레퍼런스디. 스트림에서 데이터를 읽는 메서드는 실제 스트림을 변경하기 ㅇ때문에 const로 지정하지 않앗다.
{
    string name;
    while (stream) //또는 while(!stream.fail())
    {
        int next=stream.get(); // get 으로 int 형을 저장한다 . get()은 EOF에 해당한느 std::char_traits<char>::eof()를 비롯한 문자가 아닌 특수한 값을 리턴할 수 있기 때문이다.
        if(!stream || next == std::char_traits<char>::eof())
            break;
        name += static_cast<char>(next); //문자 추가

    }
    return name;
}

void getReservationData()
{
    string guestName;
    int partySize=0;
    //숫자가 나올 때까지 문자를 읽는다.
    char ch;
    cin >> noskipws; //입력 매니퓰레이터 스트림이 공백을 건너뛰지 말고 일반 문자처럼 취급하도록
    while(cin >>ch)
    {  
        if(isdigit(ch))
        {
            cin.unget(); // 스트림이 한칸 앞으로 거슬러 올라간다.
            if(cin.fail())
            {
                cout<<"unget() failed"<<endl;
            }
            break;
        }
        guestName +=ch;
    }
    if(cin)
    {
        cin >> partySize;
    }
    if(!cin)
    {
        cerr<<"Error Getting party size. "<<endl;
        return ;
    }

    cout<<"Thank you "<<guestName
        <<"',party of "<<partySize<<endl;
    if(partySize>10)
    {
        cout<<"An extra gratuity will apply. "<<endl;
    }
}

void getReservationData2()
{
    string guestName;
    int partySize=0;
    //숫자가 나올 때까지 문자를 읽는다.
    char ch;
    cin >> noskipws; //입력 매니퓰레이터 스트림이 공백을 건너뛰지 말고 일반 문자처럼 취급하도록
    while(true)
    {  
        //peek()으로 다음 문자를 들여다 본다.
        ch = static_cast<char>(cin.peek());
        if(!cin)
            break;
        
        if(isdigit(ch))
        {
            //다음 문자가 숫자라면 종료한다.
            break;
        }
        //다음 문자가 숫자가 아니라면 계속 읽는다.
        cin>>ch;
        if(!cin)
            break;
        guestName +=ch;
    }
    if(cin)
    {
        cin >> partySize;
    }
    if(!cin)
    {
        cerr<<"Error Getting party size. "<<endl;
        return ;
    }

    cout<<"Thank you "<<guestName
        <<"',party of "<<partySize<<endl;
    if(partySize>10)
    {
        cout<<"An extra gratuity will apply. "<<endl;
    }
}



int main(int argc, char ** argv)
{
    
    // getReservationData();
    
    // getReservationData2();
    
    // char ch1;
    // cin >>ch1;
    // cin.putback('e');
    //이 스트림에서 다음번에 읽어올 문자는 'e'가 된다.
    
    //한 줄 씩 읽을 때는 getline()
    string myString;
    std::getline(cin, myString);
    cout<<myString<<endl;

    //이 부부은 파일 스트림 할 때 자세하게 나올 것 같음
    
    return 0;

}