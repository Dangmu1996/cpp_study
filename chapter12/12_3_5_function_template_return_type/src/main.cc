#include <iostream>
#include <string>


// template<typename T1, typename T2>
// auto add(const T1& t1, const T2& t2)
// {
//     return t1+t2;
// }//이렇게 하면 const 지정자는 사라진다고 함 auto로 하면 const 지정자가 사라진다고 함.

template<typename T1, typename T2>
decltype(auto) add(const T1 &t1, const T2& t2)
{
    return t1+t2;
}//이건 c++ 17 부터

// template<typename T1, typename T2>
// auto add(const T1 &t1, const T2& t2) -> decltype(t1+t2)
// {
//     return t1+t2;
// }c++14 이전


const std::string message = "Test";

const std::string& getString()
{
    return message;
}


int main(int argc, char **argv)
{
    auto result = add(1,2);

    //이렇면 const 지시자가 사라지기 때문에 s1의 타입은 string이 되면서 복제 연산이 발생한다.
    auto s1 = getString();

    //const 레퍼런스를 사용하려면 다음과 같이 레버런스와 const라는 것을 명시적으로 지정해야함
    const auto& s2 = getString();

    //또 다른 방법은 decltype을 사용하는 것 decltype을 사용하면 const나 레퍼런스가 제거되지 않는다.
    decltype(getString()) s3 = getString();

    //이렇게 하면 좀 더 간단해 보임
    decltype(auto) s4 = getString();


    return 0;
}