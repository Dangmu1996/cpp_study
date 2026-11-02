#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool perfectScore(int num)
{
    return (num>= 100);
}

int main()
{
    int num;
    vector<int> myVector;
    while(true){
        cout<<"Enter a number to add (0 to stop): ";
        cin >> num;
        if(num == 0){
            break;
        }
        myVector.push_back(num);
    }

    auto endIt = cend(myVector);
    auto it = find_if(cbegin(myVector), endIt, perfectScore);
    if(it == endIt){
        cout<<"No Perfect Scores "<<num<<endl;
    }else{
        cout<<"Found a \"perfect\" score of "<<*it<<endl;
    }
    /*
    if(auto it = find_if(cbegin(myVector), endIt, perfectScore); it == endIt){
        cout<<"No Perfect Scores "<<num<<endl;
    }else{
        cout<<"Found a \"perfect\" score of "<<*it<<endl;
    }
    */

    return 0;
}