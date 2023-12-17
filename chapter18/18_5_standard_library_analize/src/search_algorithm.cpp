#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>


using namespace std;

int main()
{
    vector<int> myVector = {5,6,9,8,8,3};
    auto beginIter = cbegin(myVector);
    auto endIter = cend(myVector);

    // 주어진 람다 표현식을 만족하지 않는 첫 번째 원소를 찾는다.
    auto it = find_if_not(beginIter, endIter, [](int i){return i < 8;});
    if(it != endIter){
        cout<<"Found element not < 8 is " << *it <<endl;
    }

    // 같은 값이 연속된 첫 번째 원소 쌍을 찾는다.
    it = adjacent_find(beginIter, endIter);
    if(it != endIter){
        cout<<"Found two consecutive equal elements with value "<<*it<<endl;
    }

    // 두 값 중 첫 번째 값을 찾는다.
    vector<int> targets = {8,9};
    it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));
    if(it != endIter){
        cout<<"Found one of 8 or 9: "<<*it<<endl;
    }

    // 첫 번째 부분열을 찾는다.
    vector<int> sub = {8, 3};
    it = search(beginIter, endIter, cbegin(sub), cend(sub));
    if(it != endIter){
        cout<<"Fouind subsequence {8,3}"<<endl;
    }else{
        cout<<"Unable to find subsequence {8,3}"<<endl;
    }

    // 마지막 부분열을 찾는다 (예제에서는 첫번째 부분열과 같다.)
    auto it2 = find_end(beginIter, endIter, cbegin(sub), cend(sub));
    if( it != it2){
        cout<<"Error: search and find_end found dirfferent subsequences "
            <<"even though ther is only one match."<<endl;
    }

    // 8이 두번연ㅅ곧된 첫번재 부분열을 찾느다.
    it = search_n(beginIter, endIter, 2, 8);
    if(it != endIter){
        cout << "Found two consecutive 8s"<<endl;
    }else{
        cout << "Unalbe to find two consecutive 8s"<<endl;
    }

    // 보이어 무어 탐색 알고리즘
    string text = "This is the haystack to search a needle in.";
    string toSearchFor = "needle";
    auto searcher = std::boyer_moore_searcher(
        cbegin(toSearchFor), cend(toSearchFor));
    
    auto result = search(cbegin(text), cend(text), searcher);
    if(result != cend(text)){
        cout<<"Found the needle."<<endl;
    }else{
        cout<<"Needle not found."<<endl;
    }

    return 0;
}