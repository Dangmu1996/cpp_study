#include <array>
#include <iostream>

using namespace std;

int main()
{
    // 세 개의 정수를 가진 배열을 생성하고, 지정된 initializer_list로
    // 값을 초기화한다.(유니폼 초기화).
    array<int, 3> arr = {9,8,7};
    // 배열의 크기를 화면에 출력한다.
    cout<<"Array size = " << arr.size() << endl; // 또는 std::size(arr);
    // 범위 기반 for 문으로 배열의 내용을 화면에 출력한다.
    for( const auto & i : arr)
    {
        cout<<i<<endl;
    }

    cout<<"Performing arr.fill(3)..."<<endl;
    // fill 메서드로 배열의 내용을 변경한다.
    arr.fill(3);
    //반복자로 배열의 원소를 모두 출력한다.
    for(auto iter = cbegin(arr); iter != cend(arr); ++iter)
    {
        cout<<*iter<<endl;
    }


    return 0;
}