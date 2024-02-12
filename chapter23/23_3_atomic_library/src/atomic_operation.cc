#include <atomic>
#include <iostream>

using namespace std;

int main()
{
    atomic<int> value(10);
    cout << "Value = " << value << endl;
    int fetched = value.fetch_add(4); // 주어진 아토믹 타입의 현재 값을 가져와서 지정한 값만큼 증가시킨 다음, 증가시키기 전의 값을 리턴한다.
    cout << "Fetched = " <<fetched << endl;
    cout << "Value = " << value << endl;

    return 0;
}