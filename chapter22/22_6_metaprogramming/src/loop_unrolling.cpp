#include <iostream>

using namespace std;

template<int i>
class Loop
{
public:
    template<typename FuncType>
    static inline void Do(FuncType func){
        Loop<i -1>::Do(func);
        func(i);
    }
};

template<>
class Loop<0>
{
public:
    template<typename FuncType>
    static inline void Do(FuncType /*func*/){ }
};

void DoWork(int i){ cout << "DoWord(" << i << ")" << endl;}

int main()
{
    Loop<3>::Do(DoWork);
}