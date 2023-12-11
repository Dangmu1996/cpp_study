#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // 값이 100보다 큰지 판단하는 제네릭 람다 표현식 정의
    auto isGreaterThan100 = [](auto i){return i > 100;};//매개변수가 auto인 것이 제네릭 람다 표현식임

    // 위에서 정의한 제네릭 람다 표현식을 정수 벡터에 적용한다.
    vector<int> ints{11,55,101,200};
    auto it1 = find_if(cbegin(ints), cend(ints), isGreaterThan100);
    if(it1 != cend(ints)){
        cout<<"Found a value > 100: "<<*it1<<endl;
    }

    // 위에서 정의한 제네릭 람다 표현식을 double vector에 적용한다.
    vector<double> doubles{11.1, 55.5, 200.2};
    auto it2 = find_if(cbegin(doubles), cend(doubles), isGreaterThan100);
    if(it2 != cend(doubles)){
        cout<<"Found a value > 100: "<<*it2 <<endl;
    }

    return 0;
}