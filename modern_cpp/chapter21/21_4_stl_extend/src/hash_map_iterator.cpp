// #include "hash_map.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;
using namespace ProCpp;

int main()
{
    hash_map<string, int> myHash;
    myHash.insert(make_pair("KeyOne", 100));
    myHash.insert(make_pair("KeyTwo", 200));
    myHash.insert(make_pair("KeyThree", 300));

    for(auto it = myHash.cbegin(); it != myHash.cend(); ++it){
        // ->와 *를 사용해서 테스트한다.
        cout << it->first << " maps to " << (*it).second << endl;
    }

    // 범위 기반의 for문을 사용해서 원소를 콘솔에 출력한다.
    for(auto& p : myHash){
        cout << p.first << " maps to " << p.second << endl;
    }

    // 범위 기반 for문과 C++17부터 추가된 구조적 바인딩을 사용해서 원소를 콘솔에 출력한다.
    for(auto&[key, value] : myHash){
        cout << key <<"maps to " << value <<endl;
    }

    // hash_map에 있는 원소를 모두 담은 std::map을 생성한다.
    map<string, int> myMap(cbegin(myHash), cend(myHash));
    for(auto &p : myMap){
        cout << p.first << "maps to " << p.second <<endl;
    }

    return 0;
}