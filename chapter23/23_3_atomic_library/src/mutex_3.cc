#include <mutex>
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

once_flag gOnceFlag;

void initializeSharedResources()
{
    // 여러 스레드가 사용할 공유 리소스를 초기화한다.
    cout << "Shared resources initialized." << endl;
}

atomic<bool> gInitialized(false);
mutex gMutex;

void processingFunction()
{
    if(!gInitialized){
        unique_lock lock(gMutex);
        if(!gInitialized){
            initializeSharedResources();
            gInitialized = true;
        }
    }
    cout<< "OK" << endl;
}

int main()
{
    // 스레드 세 개를 구동시킨다.
    vector<thread> threads;
    for(int i = 0; i< 5; ++i){
        threads.push_back(thread{processingFunction});
    }
    for(auto & t: threads){
        t.join();
    }

    return 0;
}
