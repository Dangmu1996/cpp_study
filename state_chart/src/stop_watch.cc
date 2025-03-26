#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

namespace sc = boost::statechart;

struct EvStartStop : sc::event<EvStartStop>{};
struct EvReset : sc::event<EvReset>{};

struct IElapsedTime
{
    virtual double ElapsedTime() const = 0;
};

struct Active;
struct StopWatch : sc::state_machine<StopWatch, Active>
{
    double ElapsedTime() const
    {
        return state_cast<const IElapsedTime&>().ElapsedTime();
    }
};

struct Stopped;

/*
이번 state machine은 다음과 같이 구성됨
stop watch
   - active
      - stopped
      - running

중간 Active 부분은 텝플릿에서 <자기 자신, 바로 상위 클래스, 그다음 초기 상태 이렇게 함. 이게 herical state machine으로 구성됨
*/

// transition 추가함. 이런식으로 추가하면됨 
//reset 되면 다시 active 이런식으로 하면 밑에 process event 할때,
// transition이 실행되는 것 같음
struct Active : sc::simple_state<Active, StopWatch, Stopped>
{
    public:
        typedef sc::transition<EvReset, Active> reactions;

        Active() : elapsedTime_(0.0){}
        double ElapsedTime() const {return elapsedTime_;}
        double & ElapsedTime() { return elapsedTime_; }
    private:
        double elapsedTime_;
};

// running 상태에서 Evstartstop 있으면 running으로
struct Running : IElapsedTime, sc::simple_state<Running, Active>
{
    public:
        typedef sc::transition<EvStartStop, Stopped> reactions;
        Running() : startTime_(std::time(0)){}
        ~Running(){
            context<Active>().ElapsedTime() = ElapsedTime();
        }

        virtual double ElapsedTime() const
        {
            return context<Active>().ElapsedTime() + std::difftime(std::time(0), startTime_);
        }
    
    private:
        std::time_t startTime_;
};

struct Stopped : IElapsedTime, sc::simple_state<Stopped ,Active> 
{
    typedef sc::transition<EvStartStop, Running> reactions;
    virtual double ElapsedTime() const
    {
        return context<Active>().ElapsedTime(); // 부모 state class에 접근할 때에는 context<부모 클래스 이렇게 접근
    }
};

int main()
{
    StopWatch myWatch;
    myWatch.initiate();
    std::cout << myWatch.ElapsedTime() << "\n";
    myWatch.process_event(EvStartStop());
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << myWatch.ElapsedTime() << "\n";
    
    myWatch.process_event(EvStartStop());
    std::cout << myWatch.ElapsedTime() << "\n";
    myWatch.process_event(EvStartStop());
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << myWatch.ElapsedTime() << "\n";
    myWatch.process_event(EvReset());
    std::cout << myWatch.ElapsedTime() << "\n";
    return 0;
}