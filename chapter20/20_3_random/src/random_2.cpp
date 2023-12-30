#include <algorithm>
#include <random>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 메르센 트위스터 엔진 사용 예시
    // 처음 시드를 random_Ddevice를 사용하여 생성. 안되면 시스템 시간에 기반한 시드를 사용
    random_device seeder;
    const auto seed =seeder.entropy() ? seeder() : time(nullptr);
    mt19937 eng(static_cast<mt19937::result_type>(seed));

    // 1부터 99 사이의 귱등 정수 분표로 지정 균등 정수 분포로 지정
    uniform_int_distribution<int> dist(1,99); 

    // bind로 dist()의 첫번째 매게 변수를 eng()로 바인딩해서 gen()을 정의함. 이렇게 하면 무작위수를 생성할 때마다 인수를 지정하지 않고  gen()만 호출 할 수 있다. 
    auto gen = std::bind(dist, eng);

    vector<int> vec(10);
    generate(begin(vec), end(vec), gen);

    for(auto i : vec){ cout<< i << " ";}

    return 0;
}