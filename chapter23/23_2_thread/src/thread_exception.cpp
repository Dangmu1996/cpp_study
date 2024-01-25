#include <thread>
#include <iostream>
#include <stdexcept>

using namespace std;

void doSomeWork()
{
    for(int i = 0; i < 5; ++i){
        cout << i <<endl;
    }
    cout << "Thread throwing a runtime_error_exception..." << endl;
    throw runtime_error("Exception from thread");
}

void threadFunc(exception_ptr& err)
{
    try{
        doSomeWork();
    }catch(...){
        cout << "Thread caught exception, returning exception..." << endl;
        err = current_exception(); //catch 블록에서 호출하며, 현재 처리할 익셉션을 가리키는 exception_ptr 객체나 그 복사본을 리턴한다.
    }
}

void doWorkInThread()
{
    exception_ptr error;
    
    // 쓰레드를 구동한다.
    thread t{threadFunc, ref(error)};
    
    // 스레드가 종료할 때까지 기다린다.
    t.join();

    // 스레드에 익셉션이 발생했는지 검사한다.
    if(error){
        cout << "Main thread received exception, rethrowing it..." << endl;
        rethrow_exception(error);
    }else{
        cout << "Main thread did not receive any exception." << endl;
    }
}

int main()
{
    try{
        doWorkInThread();
    }catch(const exception& e){
        cout << "Main function caught: '"<< e.what() << "'" << endl;
    }

    return 0;
}