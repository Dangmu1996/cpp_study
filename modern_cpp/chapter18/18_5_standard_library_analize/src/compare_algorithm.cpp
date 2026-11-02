#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// int 타입 컨테이너에 원소를 채우는 함수 템플릿
// 이때 컨테이너는 반드시 push_back()을 제공해야 한다.
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
   list<int> myList;

   cout<<"Populate the vector:"<<endl;
   populateContainer(myVector);
   cout<<"Populate the list:"<<endl;
   populateContainer(myList);

   // 두 컨테이너를 비교한다.
    if(equal(cbegin(myVector),cend(myVector),
        cbegin(myList), cend(myList))){
            cout<<"The two containers have equal elemetns"<<endl;
    }else{
        // 두 컨테이너가 다르면 그 이유를 알아낸다.
        auto miss = mismatch(cbegin(myVector), cend(myVector),
                            cbegin(myList), cend(myList));
        cout << "The following initial elements are the same in"
            << "the vector and the list:"<<endl;
        for(auto i = cbegin(myVector); i != miss.first; ++i){
            cout<<*i<<'\t';
        }
        cout<<endl;
    }

    // 순서를 비교한다.
    if(lexicographical_compare(cbegin(myVector), cend(myVector),
                                cbegin(myList), cend(myList))){
        cout<<"The vector is lexicographically first"<<endl;
    }else{
        cout<<"The list is lexicographically first"<<endl;
    }
    return 0;
}