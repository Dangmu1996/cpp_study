#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::vector<double> doubleVector(10); //double 값 열 개를 담을 vector를 생성한다.

    // 최댓값(max)을 double의 촛솟값으로 초기화한다.
    double max = -std::numeric_limits<double>::infinity();

    for(size_t i = 0; i<doubleVector.size(); i++)
    {
        std::cout<<"Enter score "<<i+1<<": ";
        std::cin>>doubleVector[i];
        if(doubleVector[i]>max)
        {
            max=doubleVector[i];
        }
    }

    max /= 100.0;
    for(auto& element : doubleVector)
    {
        element /= max;
        std::cout<<element<<" ";
    }

    return 0;
}