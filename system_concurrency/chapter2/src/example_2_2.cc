#include <thread>

struct func
{
    int &i;
    func(int & i_) : i(i_) {}

    void operator()()
    {
        for(unsigned j =0; j<1000000; ++j)
        {
            do_something(i);
        }
    }
};


void f()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try{
        // 현재 스레드에서 수행할 작업
        do_something_in_current_thread();
    }
    catch(...)
    {
        // 현재 작업에서 예외가 발생했을때, 실행
        t.join(); // 작업 스레드가 끝날 때까지 기다림
        throw; // 잡았던 예외를 다시 바깥으로 전달
    }
    // 현재 작업이 정상적으로 끝났을때
    t.join();
}

// 이건 코드가 길어지고 중간에 return 같은 다른 탈출 경로가 추가되면 빠뜨리기 쉬워짐
