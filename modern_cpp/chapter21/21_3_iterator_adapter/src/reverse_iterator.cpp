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
    vector<int> myVector;
    populateContainer(myVector);

    int num;
    cout << "Enter a number to find: ";
    cin >> num;

    auto it1 = find(begin(myVector), end(myVector), num);
    auto it2 = find(rbegin(myVector), rend(myVector), num);
    if(it1 != end(myVector)){
        cout << "Found " << num << " at position " << it1 - begin(myVector) << " going forward." << endl;
        cout << "Found " << num << " at position " << it2.base() -1 - begin(myVector) << " gowing backward."<<endl;
    }else{
        cout << "Failed to find " << num <<endl;
    }

    return 0;
}