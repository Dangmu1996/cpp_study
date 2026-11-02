#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;

double arithmeticMean(const vector<int>& nums)
{
    double sum = accumulate(cbegin(nums), cend(nums), 0); //3번째 값은 초기값 설정한 것임.
    return sum / nums.size();
}

int product(int num1, int num2)
{
    return num1 * num2;
}

double geometricMean(const vector<int>& nums)
{
    double mult = accumulate(cbegin(nums), cend(nums), 1, product);
    return pow(mult, 1.0 / nums.size());
}

double geometricMeanLamda(const vector<int>& nums)
{
    double mult = accumulate(cbegin(nums), cend(nums), 1,
    [](int num1, int num2){ return num1 * num2;});
    return pow(mult, 1.0 / nums.size());
}

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    vector<int> a = {1,2,3};
    cout<<arithmeticMean(a)<<endl;
    cout<<geometricMean(a)<<endl;
    cout<<geometricMeanLamda(a)<<endl;

    return 0;

}