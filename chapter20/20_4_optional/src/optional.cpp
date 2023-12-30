#include <optional>
#include <iostream>

using namespace std;
// 어떤 타입의 값이 있거나 없을 수 있는 것을 표현한다.
optional<int> getData(bool giveIt)
{
    if(giveIt){
        return 42;
    }
    return nullopt; // 또는 그냥 return {}; 이라고만 적는다.
}

int main()
{
    auto data1 = getData(true);
    auto data2 = getData(false);

    cout<<"data1.has_value = " << data1.has_value() << endl;
    if(data2){
        cout << "data2 has a value. "<<endl;
    }

    cout << "data1.value = " << data1.value() <<endl;
    cout << "data1.value = " << *data1 << endl;

    // 값이 없는  optional에 value() 메서드를 호출하면 bad_optional_access 익셉션이 발생한다.
    // vlaue_or()을 호출하면 optional에 값이 있으면 그 값을 리턴하고, 값이 없으면 다른 값을 리턴한다.
    cout<<"data2.value = " << data2.value_or(0) << endl;

    return 0;
}