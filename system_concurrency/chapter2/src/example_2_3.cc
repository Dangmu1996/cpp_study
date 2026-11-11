#include <thread>

class thread_guard
{
    /* 이거 소멸 되면서 자연스럽게, thread 도 함께 소멸되도록 함 */
    std::thread &t;
public:
    // 이거 explicit 생성자, thread_guard 객체를 만들때, std::thread 객체를 참조로 받아서 초기화
    // explicit 안붙이면, 어떤 미친놈이, thread_guard g = t; 이런식으로 만들수 있음, 이거 방지하려고 explicit 붙임
    explicit thread_guard(std::thread &t_): t(t_) {}

    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }

    // 복사 생성자와 대입 연산자를 삭제해서, thread_guard 객체가 복사되거나 대입되는 것을 방지
    // 복사 되면 join()이 두번 호출될 수 있어서, thread_guard 객체는 복사되거나 대입될 수 없도록 함
    // thread_guard 객체는 소유권을 가지므로, 복사되면 join()이 두번 호출될 수 있음
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
}

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
    thread_guard g(t);

    do_something_in_current_thread();
    
}

// 예제 2.3에서 joint() 되기 전에, 그리거 놓치기 쉬운 상황을 막기 전에 thread_guard를 만들어서,
// thread_guard의 소멸자가 호출될때 join()이 호출되도록 함.

