#include <thread>
#include <iostream>

using namespace std;

void counter(int id, int numIterations)
{
    for(int i = 0; i<numIterations; ++i)
    {
        cout << "Counter " << id << " has value " << i <<endl;
    }
}

int main()
{
    thread t1(counter, 1, 6);
    thread t2(counter, 2, 4);

    // thread 객체가 실행 가능한 상태에 있을 때, 조인 가능 joinable 하다고 표현
    // 디폴트로 생성된 thread 객체는 조인 불가능 unjoinable 하다고 표현
    // join()을 호출하면 그 스레드는 블록된다. -> 막힌다는 뜻임 끝날때까지 기다림
    // detach()를 호출하면 thread 객체를 OS 내부의 스레드와 분리한다. 그래서 OS 스레드는 독립적으로 실행된다.
    // detach()를 종료시키려면 std::terminate()를 호출하여 모든 스레드 뿐만 아니라 어플리케이션을 종료시켜야 함.
    t1.join();
    t2.join();

    return 0;
}