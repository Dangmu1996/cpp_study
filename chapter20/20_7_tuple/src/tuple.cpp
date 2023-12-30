#include <tuple>
#include <string>
#include <iostream>
#include <utility>
#include <functional>

using namespace std;

int main()
{
    using MyTuple = tuple<int, string, bool>;
    MyTuple t1(16, "Test", true);

    // std::get<i> ()는 tuple의 i번째 원소를 가져온다. 
    cout<<"t1 = (" << get<0>(t1) << ", " << get<1>(t1)
        <<", " << get<2>(t1) << ")" << endl;

    cout << "Type of get<1>(t1) = "<< typeid(get<1>(t1)).name() << endl;
    
    cout<<"String = " << get<string>(t1)<<endl;

    cout << "Tuple Size = " <<tuple_size<MyTuple>::value << endl;

    double d= 3.14;
    string str1 = "Test";
    std::tuple t2(16, ref(d), cref(d), ref(str1));

    cout << "d = " << d << endl;
    get<1>(t2) *= 2;
    cout << "d = " << d << endl;

    return 0;
}