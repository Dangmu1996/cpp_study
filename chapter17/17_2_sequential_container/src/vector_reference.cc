#include <vector>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
    //vector에 reference를 저장할 때
    string str1 = "Hello";
    string str2 = "World";

    // 스트링에 대한 레퍼런스를 담는 vector를 생성한다.
    vector<reference_wrapper<string>> vec{ref(str1)};
    vec.push_back(ref(str2)); //push_back()을 호출할 때도 ref()를 사용할 수 있다.

    // 앞에서 만든 vector의 두 번째 원소 (레퍼런스)가 참조하는 스트링갑을 변경한다.
    vec[1].get() += "!";

    // 최종 결과(변경된 str2 값)를 출력한다.
    cout<< str1 << " " << str2 <<endl;

    return 0;
}