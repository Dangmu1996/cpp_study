#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char ** argv)
{
    //put 과 write는 저수준 출력 메서드
    const char* test ="hello there\n";
    cout.write(test, strlen(test));

    cout.put('a');

    /*stream에서 output은 효율성 때문에 buffrer에 대이터를 저장했다가
    output을 뽑아내는데 이때, 다음과 같은 조건일때 buffer를 비우며 output을 준다.
    - endl과 같은 경곗값에 도달할 때
    - 스트림이 스코프를 벗어나 소멸될때
    - 출력 스트림에 대응되는 입력 스트림으로 부터 요청이 들어올때
    - 스트림 버퍼가 가득 찼을 때
    - 스트림 버퍼를 비우기 위해 명시적으로 flush()를 호출할 때
    */

    cout<<"abc";
    cout.flush(); // 콘솔에 abc 출력

    cout<<"def";
    cout<<endl; // 콘솔에 def가 출력

    //good() 메서드는 스트림을 정상적으로 사용할 수 있는 상태인지 확인한다.
    if(cout.good())
    {
        cout<<"all good"<<endl;
    }

    //뭔가 잘못 되면 bad 는 true 임 
    if(cout.bad())
    {
        cout<<"something bad"<<endl;
    }

    //파일 끝에 도달하면 eof true
    if(cout.eof())
    {
        cout<<"end of file not the bad"<<endl;
    }

    //fail()은  바로 전에 호출한 연산이 성공했는지 확인
    cout.flush();
    if(cout.fail())
    {
        cerr<<"Unable to flush to standard out"<<endl;
    }

    //이건 예외처리 ios_base::failure& 보면 알 수 있음
    cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
    try
    {
        cout<<"hello world"<<endl;
    }
    catch(const ios_base::failure& ex)
    {
        cerr<<"Caught exception : " << ex.what() << ", error code = " << ex.code() << endl;
    }

    //스트림의 에러 상태를 초기화 하려면 clear()
    cout.clear();


    return 0;
}