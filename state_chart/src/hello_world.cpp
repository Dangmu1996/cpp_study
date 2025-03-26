#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <iostream>
#include <thread>
#include <atomic> // theading에서 공유되는 변수는 atomic으로 사용하는게 좋음 병렬 프로그래밍 참고
#include <chrono>

namespace sc = boost::statechart;

// Greething의 initial state 선언
struct Greeting;

// state mahcine 클래스를 정의 한다. 첫번째 템플릿 인자에는 자기 자신을 넣고
// 두번째 인자에는 초기 상태를 지정한다.
struct Machine : sc::state_machine<Machine, Greeting>{};


// Greeting 상태를 sc::simple_state를 이용해 정의한다.
// Entry 동작은 생성자에서, Exit 동작은 소멸자에서 처리한다.
// 첫 번째 템플릿 인자는 자기 자신(Greeting)이며,
// 두 번째 템플릿 인자는 이 상태가 속하는 상위 컨텍스트(Machine)를 의미한다.
// HFSM(Hierarchical Finite State Machine, 계층적 유한 상태 기계)이 아닌
// Flat State Machine(평탄한 상태 기계)에서는 항상 Machine이 두 번째 인자가 된다.
// 그리고 보통 Do activity 관련해서는 Threading으로 처리함
struct Greeting : sc::simple_state<Greeting, Machine>
{
    std::atomic<bool> active;
    std::thread doActivityThread;

    Greeting() //entry
    : active(true)
    {
        std::cout<<"Hello World!\n";

        //do
        doActivityThread = std::thread([this](){
            while(active.load()){
                std::cout<<"Doing something...\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        });
    }

    ~Greeting()//exit
    {
        active.store(false);
        if(doActivityThread.joinable()){
            doActivityThread.join(); // wait for thread finish
        }
        std::cout<<"Bye Bye World!\n";
    }
};

int main()
{
    Machine myMachine;
    myMachine.initiate();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
