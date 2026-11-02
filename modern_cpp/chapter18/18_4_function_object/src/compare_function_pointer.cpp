#include <queue>
#include <iostream>
#include <vector>
using namespace std;

// equal_to, not_equal_to, less_greater, less_equal, greater_equal

int main()
{
    // priority_queue<int> myQueue;
    priority_queue<int, vector<int>, greater<>> myQueue;
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(2);

    myQueue.push(1);
    while(!myQueue.empty()){
        cout<<myQueue.top()<<" ";
        myQueue.pop();
    }

    // priority queue 이렇게 되어 있다. 마지막 compare이 less로 되어 있음.
    // template<class T, class Container = vector<T>, class Compare = less<T>>
    // 컨테이너 사용할 때는 항상 투명 연산자
    

    return 0;
}