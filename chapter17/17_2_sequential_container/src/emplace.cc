#include <vector>
#include <string>

using namespace std;

int main()
{
    std::vector<std::string> vec;
    vec.emplace_back(5, 'a');
    // 이 메서드는 복제나 이동 작업을 수행하지 않고, 컨테이너에 공간을 마련해서 객체를 그 자리에 바로 생성한다.
    // 근데 성능 자체는 push_back이랑 컴파일러의 버전에 따라 다르다고 함.

    vec.push_back(string(5, 'a'));
    return 0;
}