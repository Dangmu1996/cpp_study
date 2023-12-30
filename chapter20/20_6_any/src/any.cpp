#include <any>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 모든 타입의 값을 저장하는 클래스

int main()
{
    any empty;
    any anInt(3);
    any aString("An std::string"s);

    cout << "empty.has_value = " << empty.has_value() << endl;
    cout << "anInt.has_value = " << anInt.has_value() << endl << endl;

    cout << "anInt wrapped type = " << anInt.type().name() << endl;
    cout << "aString wrapped type = " << aString.type().name() << endl << endl;

    int theInt = any_cast<int>(anInt);
    cout << theInt << endl;

    try{
        int test = any_cast<int>(aString);
        cout<<test<<endl;
    }catch(const bad_any_cast& ex){
        cout<<"Exception: "<<ex.what()<<endl;
    }

    any something(3); //이렇게 하면 정숫값을 가진다.
    something = "An std::string"s; // 이렇게 하면 같은 인스턴스에 스트링이 담긴다.

    // any의 인스턴스를 표준 라이브러리 컨테이너에 저장할 수도 있다.
    // 한 가지 단점은 특정한 값을 가져올 때마다 명시적으로 any_cast를 적용해야 한다.
    vector<any> v;
    v.push_back(any(42));
    v.push_back(any("An std::string"s));

    cout<<any_cast<string>(v[1])<<endl;

    return 0;
}