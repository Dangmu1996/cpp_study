#include <cstdio>
#include <cstdarg>
#include <iostream>

using namespace std;

bool debug = false;

void debugOut(const char* str, ...) //...이게 임의 개수와 타입의 인수를 받을 수 있다는 것을 의미한다.
{
    va_list ap; // va_list 타입의 변수 선언
    if(debug)
    {
        va_start(ap, str); // 초기화를 한다고 함 두번째 매개변수는 반드시 매개변수 리스트의 이름 있는 변수 중에서 오른쪽 끝에 있는 것이여야 한다고 함 뭔소린지 모르겠네, 오른쪽이 아니라 왼쪽 인듯
        vfprintf(stderr, str, ap);  // 이건 걍 cstdio에 있는 것 이라고 함
        va_end(ap); // 가변 길이 인수 리스트에 대한 접근을 종료한다. 뭔가 초기화 start로 해 줬으니까 end로 종료하는 듯 
    }
} // 디버그 플래그가 설정됐다면 stderr로 스트링을 출력하고 그렇지 않으면 아무 일도 하지 않는 디버깅 함수를 구현

//이건 처음에 들어오는 정수 값으로 출력할 숫자의 개수를 정할 수 있다고함.
void printInts(size_t num, ...)
{
    int temp;
    va_list ap;
    va_start(ap, num);
    for(size_t i=0; i<num; i++)
    {
        temp=va_arg(ap, int); //이걸로 하면 인수에 접근이 가능하다고 함
        cout << temp << " ";
    }
    va_end(ap);
    cout<<endl;
}


int main(int argc, char ** argv)
{
    debug = true;
    debugOut("int %d\n", 5);
    debugOut("String %s and int %d\n", "hello", 5);
    debugOut("Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);
    debugOut("Many ints: %d, %d, %d, %d, %d\n", "hl", 2, 3, 4, 5); //걍 쓰레기값 들어오던데

    printInts(5, 1, 2, 3, 4, 5, 6); //이럼 5까지만 print 함
    
    return 0;
} //동작해 보면 printf 처럼 행동함 가변길이 인수를 사용하는 것이라고 하고 뒤에 들어가는 인수 들어오는 것 만큼 가변해서 처리하는 것임

//일단 이렇게 인수를 여러게 받을 수 있다는 것만 알고 있으면 좋을 듯
//근데 책에서 이런거 있으니까 쓰면 좋을 수도 있다고 하고 마지막에는 쓰면 안된느 이유를 설명하네... 걍 사람이 뒤에 인수를 알맞게 넣을 지 모른다 이소리함. 걍 vector랑 array 써서 안에 값을 담아서 전달하라고 함, 그래도 알고 있으면 어딘가에는 쓰겠지