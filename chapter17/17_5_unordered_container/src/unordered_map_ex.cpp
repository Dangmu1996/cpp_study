#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    unordered_map<int, string> m ={
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"}
    };

    // C++17부터 추가된 구조적 바인딩을 적용한다.
    for(const auto &[key, value] : m)
    {
        cout<<key<<"="<<value<<endl;
    }

    // 구조적 바인딩을 적용하지 않는다.
    for(const auto & p : m)
    {
        cout<<p.first << " = "<<p.second<<endl;
    }

    return 0;
}