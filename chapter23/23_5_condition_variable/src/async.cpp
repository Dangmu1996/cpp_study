#include <iostream>
#include <thread>
#include <future>

using namespace std;
// using namespace launch;

/*
launch::async: 주어진 함수를 다른 스레드에서 실행시킨다.
launch::deferred: get()을 호출할 때 주어진 함수를 현재 스레드와 동기식으로 실행시킨다.
launch::async | launch::deferred: C++ 런타임이 결정한다(디폴트 동작)
*/
int calculate()
{
    return 123;
}


int main()
{
    auto myFuture = async(calculate);
    // auto myFuture = async(launch::async, calculate);
    // auto myFuture = async(launch::deferred, calculate);

    // 다른 작업을 수행한다.

    // 결과를 가져온다.
    int result = myFuture.get();
    cout << result << endl;

    return 0;
};