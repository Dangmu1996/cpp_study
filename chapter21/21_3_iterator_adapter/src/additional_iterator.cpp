#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

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
    vector<int> vectorOne, vectorTwo;
    populateContainer(vectorOne);

    // back_insert_iterator<vector<int>> inserter(vectorTwo);
    // copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
    //     [](int i){ return i != 100;});

    copy_if(cbegin(vectorOne), cend(vectorOne), back_insert_iterator(vectorTwo), [](int i){return i!= 100;});

    copy(cbegin(vectorTwo), cend(vectorTwo), ostream_iterator<int>(cout, " "));

    return 0;
}