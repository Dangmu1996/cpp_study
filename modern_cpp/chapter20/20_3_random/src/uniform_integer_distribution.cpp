#include <random>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    const unsigned int kStart = 1;
    const unsigned int kEnd = 99;
    const unsigned int kIterations = 1'000'000;

    // 균등 메르센 트위스터
    random_device seeder;
    const auto seed = seeder.entropy() ? seeder() : time(nullptr);
    mt19937 eng(static_cast<mt19937::result_type>(seed));
    // uniform_int_distribution<int> dist(kStart, kEnd);
    normal_distribution<double> dist(50, 10);

    auto gen = bind(dist, eng);
    map<int, int> m;
    for(unsigned int i = 0; i<kIterations; i++)
    {
        // int rnd = gen();
        int rnd = static_cast<int>(gen()); 
        // map에서 key == rnd인 망목을 찾는다. 발견하면 그 키의 값에 1을 더한다.
        // 없다면 키를 map에 저장하고 값을 1로 지정한다.
        ++(m[rnd]);
    }

    // CSV 파일에 쓴다.
    ofstream of("../data/res_nor.csv");
    for(unsigned int i = kStart; i <= kEnd; ++i){
        of << i << "," << m[i] << endl;
    }

    return 0;
}