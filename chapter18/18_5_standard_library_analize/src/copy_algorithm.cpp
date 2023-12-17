#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename Container>
void populateContainer(Container& cont)
{
    int num;
    while(true){
        cout<<"Enter a number {0 to quit}: ";
        cin>>num;
        if(num == 0){
            break;
        }
        cont.push_back(num);
    }
}

int main()
{
    vector<int> vec1, vec2;
    populateContainer(vec1);

    vec2.resize(size(vec1));
    //copy(cbegin(vec1), cend(vec1), begin(vec2));
    //copy_backward(cbegin(vec1), cend(vec1), end(vec2));
    // 짝수만 복사
    auto endIterator = copy_if(cbegin(vec1), cend(vec1),
         begin(vec2), [](int i){return i%2 == 0;});
    vec2.erase(endIterator, end(vec2));
    
    for(const auto & i :vec2){cout<<i<<" ";}

    return 0;
}