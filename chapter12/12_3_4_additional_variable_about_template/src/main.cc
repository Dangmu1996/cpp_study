#include <iostream>

using namespace std;

//return 값에 대해서 default
template<typename ReType = long long, typename T1, typename T2>
ReType add(const T1& t1, const T2& t2)
{
    return t1 + t2;
}

int main(int argc, char **argv)
{
    auto result = add<long long, int, int>(1, 2);
    cout<<result<<endl;
    // 매개변수로 입력 변수를 추론해 int로 알아서 설정함.
    auto result2 = add<long long>(1,2);
    cout<<result2<<endl;

    // return 에 대해서 default 있으니까
    auto result3 = add(1,2);
    cout<<result3<<endl;
    return 0;
}