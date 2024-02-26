#include <mutex>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;


/*
std::call_once()와 std::once_flag를 함께 사용하면 once_flag에 대해 여러 스레드가 call_once()를 호출하더라도 call_once의 인수로 지정한 함수나 메서드가 단 한번만 호출되게 할 수 있다.

인수로 지정한 함수나 메서드에 대해 call_once가 단 한번만 호출된다.

지정한 함수가 익셉션을 던지지 않을 때 이렇게 호출하는 것을 이펙티브 call_once() 호출이라 부른다. 

지정한 함수가 익셉션을 던지면 그 익셉션은 호출한 측으로 전달되며, 다른 호출자를 골라서 함수를 실행 시킨다.

특정한 once_flag 인스턴스에 대한 이펙티브 호출은 동일한 once_flag에 대한 다른 call_once() 호출보다 먼저 끝난다.
*/


/*
다음 예시는 스레드마다 once_flag라는 전역 플레그에 대해 call_once()를 호출한다.
코드를 실행하면 단 한 스레드만 initializeSharedResource()를 정확히 한 번만 실행한다.
call_once() 호출이 진행는 동안 다른 스레드는 initializeSharedResources()가 리턴할 때까지 블록된다.
*/
once_flag gOnceFlag;

void initializeSharedResources()
{
    // 여러 스레드가 사용할 공유 리소스를 초기화한다.
    cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
    // 공유 리소스를 반드시 초기화한다.
    call_once(gOnceFlag, initializeSharedResources);

    // 원하는 작업을 수행한다. 이때 리소스를 사용한다.
    cout << "Processing" <<endl;
}

int main()
{
    // 스레드 세 개를 구동시킨다.
    vector<thread> threads(3);
    for(auto& t: threads){
        t= thread{processingFunction};
    }

    // 각 스레드에 대해 join()을 호출한다.
    for(auto& t:threads){
        t.join();
    }

    return 0;
}
