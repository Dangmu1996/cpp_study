#include <vector>
#include <iostream>

int main()
{
    std::vector<int> intVector(10);

    // 어떤 작업을 하고 원소 10개를 삭제한 뒤 값이 100인 원소 다섯 개를 추가한다.
    intVector.assign(5, 100);
    intVector.assign({1, 2, 3, 4});

    std::vector<int> vectorOne(10);
    std::vector<int> vectorTwo(5, 100);
    vectorOne.swap(vectorTwo);
    // vectorOne은 값이 100인 원소 다섯 개를 갖고,
    // vectorTwo는 값이 0인 원소 열 개를 갖게 된다.


    return 0;
}