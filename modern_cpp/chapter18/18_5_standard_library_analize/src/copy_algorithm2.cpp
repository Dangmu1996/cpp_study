#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

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

    size_t cnt = 0;
    cout<<"Enter number if elements you want to copy: ";
    cin >> cnt;
    cnt = min(cnt, size(vec1));
    vec2.resize(cnt);
    copy_n(cbegin(vec1), cnt, begin(vec2));
    for(const auto & i : vec2){ cout<<i<<" ";}

    return 0;
}