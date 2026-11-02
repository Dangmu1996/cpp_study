#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

bool perfectScore(int score)
{
    return score>100;
}

void findEmptyString(const vector<string>& strings)
{
    auto endIter = end(strings);
    auto it = find_if(begin(strings), endIter, mem_fn(&string::empty)); // mem_fn이면 string의 empty를 펑터로 받음
    // 람다 표현식으로는 다음과 같이 표현 가능
    // auto it = find_if(begin(strings), endIter, [](cosnt string& str){ return str.empty()};
    if(it == endIter){
        cout<<"No empty strings!"<<endl;
    }else{
        cout<<"Empty string at position: "
            << static_cast<int>(it - begin(strings)) << endl;
    }
}

void printMessage(string_view message){ cout<< message <<endl;}

int main()
{
    vector<int> myVector{11, 22, 33, 44, 55, 112, 101, 115};
    auto endIter = end(myVector);
    auto it = find_if(begin(myVector), endIter, not_fn(perfectScore));
    // auto it = find_if(begin(myVector), endIter, [](int i){return i< 100;}); // 그냥 이렇게 람다 표현식이 좋다고 함.
    if(it==endIter){
        cout<<"All perfect scores"<<endl;
    }else{
        cout<<"Found a \"less-than-perfect\" scroe of "<< *it<< endl;
    }

    invoke(printMessage, "Hello invoke.");
    invoke([](const auto &msg){cout<<msg<<endl;},"Hello invoke.");
    string msg = "Hello invoke. ";
    cout<<invoke(&string::size, msg)<<endl;

    return 0;
}