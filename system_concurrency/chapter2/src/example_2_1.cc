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


void oops()
{
    int some_local_state = 0; // 이거 복사함 func에서
    func my_func(some_local_state); // 요기서 ref로 복사
    std::thread my_thread(my_func); // operator() 호출 저 operator()있으면 callable이라고 함
    my_thread.detach(); // 댕글링 참조라고 하는데, detach 하면 t작업이 끝날때까지 기다리지 않고, 객체와 실행 스레드의 연결을 끊음 요기서 작업이 계속 실행 될 수 있음
} // 지역 변수의 수명은 끝났지만, 새 스레드는 아직 실행 중일 수 있음, 그래서 저 i가 dangling reference가 됨, 그래서 이거는 위험함, 그래서 detach는 잘 안씀, join을 쓰는게 안전함
