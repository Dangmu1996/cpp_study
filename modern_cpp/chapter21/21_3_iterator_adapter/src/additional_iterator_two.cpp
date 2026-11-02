#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

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
    vector<int> vectorOne;
    set<int> setOne;

    populateContainer(vectorOne);

    insert_iterator<set<int>> inserter(setOne, begin(setOne));

    copy_if(cbegin(vectorOne), cend(vectorOne), inserter, [](int i){return i != 100;});

    copy(cbegin(setOne), cend(setOne), ostream_iterator<int>(cout, " "));

    return 0;
}