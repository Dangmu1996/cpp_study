#include "hash_map.hpp"
#include <iostream>

using namespace std;
using namespace ProCpp;

int main()
{
    hash_map<int, int> mHash;
    mHash.insert(make_pair(4, 40));
    mHash.insert(make_pair(6, 60));

    // x의 타입은 hash_map<int, int>::value_type*다.
    auto x= mHash.find(4);
    if(x!=nullptr){
        cout << "4 maps to " << x->second << endl;
    }else{
        cout << "cannot find 4 in map"<<endl;
    }

    mHash.erase(4);
    auto x2 = mHash.find(4);
    if(x2 != nullptr){
        cout <<"4 maps to "<<x2->second << endl;
    }else{
        cout << "cannot find 4 in maps" << endl;
    }

    mHash[4] = 35;
    mHash[4] = 60;

    auto x3 = mHash.find(4);
    if(x3 != nullptr){
        cout << "4 maps to " << x3->second << endl;
    }else{
        cout << "cannot find 4 in map" << endl;
    }

    // std::swap()에 대한 테스트 코드
    hash_map<int, int> other(std::equal_to<>(), 11);
    swap(other, mHash);
    
    // 복제 생성자와 복제 대입 연산자에 대한 테스트코드
    hash_map<int, int> myHash2(other);
    hash_map<int, int> myHash3;
    myHash3= myHash2;

    // 이동 생성자와 이동 대입 연산자에 대한 테스트 코드
    hash_map<int, int> myHash4(std::move(myHash3));
    hash_map<int, int> myHash5;
    myHash5 = std::move(myHash4);
    return 0;
}