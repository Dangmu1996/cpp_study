#include <vector>
#include <iostream>
#include <limits>

int main()
{
    std::vector<double> doubleVector; //빈 vector를 생성한다.

    double max = -std::numeric_limits<double>::infinity();
    double temp;

    for(size_t i=1; true; i++)
    {
        std::cout<<"Enter score "<<i<<" (-1 to stop): ";
        std::cin>>temp;
        if(temp == -1)
        {
            break;
        }
        doubleVector.push_back(temp);
        if(temp>max)
        {
            max = temp;
        }
    } 

    max /= 100.0;
    for(auto& element : doubleVector)
    {
        element /= max;
        std::cout << element << " ";
    }

    return 0;
}