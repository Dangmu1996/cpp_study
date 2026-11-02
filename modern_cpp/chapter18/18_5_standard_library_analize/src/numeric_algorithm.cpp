#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1{ 1, 2, 3, 4};
    vector<int> v2{ 9, 8, 7, 6};

    cout<<inner_product(cbegin(v1), cend(v1), cbegin(v2), 0) << endl;
    
    vector<int> vec(10);
    iota(begin(vec), end(vec), 5);
    for(auto& i : vec){cout<< i << " ";}

    // 최대 공약수 , 최대 공배수
    auto g = gcd(3, 18); // g= 3
    auto l = lcm(3. 18); // l = 18
    
    
    return 0;
}