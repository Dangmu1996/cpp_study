#include <vector>
#include <iostream>

using namespace std;

int main()
{
    const size_t count = 10;
    int arr[count]; // 표준 C 스타일 배열
    // 배열의 원소를 모두 인덱스 값으로 초기화한다.
    for(int i=0; i<count; i++)
    {
        arr[i]= i;
    }

    //배열에 담긴 내용을 vector 뒤에 추가한다.
    vector<int> vec;
    vec.insert(end(vec), arr, arr+count);
    //vec.insert(end(vec), cbegin(arr), cend(arr));

    //voector의 내용을 화면에 출력한다.
    for(const auto &i: vec)
    {
        cout<<i<<" ";
    }

}