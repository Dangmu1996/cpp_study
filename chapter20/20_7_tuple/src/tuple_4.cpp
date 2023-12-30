#include <tuple>
#include <iostream>
#include <string>

using namespace std;

struct Foo
{
    int mInt;
    string mStr;
    bool mBool;
};

bool operator<(const Foo& f1, const Foo& f2)
{
    return tie(f1.mInt, f1.mStr, f1.mBool) < tie(f2.mInt, f2.mStr, f2.mBool);
}

int main()
{
    tuple<int, string> t1(123, "def");
    tuple<int, string> t2(123, "abc");

    if(t1< t2){
        cout << "t1 < t2" <<endl;
    }else{
        cout << "t1 >= t2" << endl;
    }

    Foo f1{42, "Hello", false};
    Foo f2{32, "World", false};
    cout << (f1 < f2) << endl;
    cout << (f2 < f1) << endl;

    return 0;
}