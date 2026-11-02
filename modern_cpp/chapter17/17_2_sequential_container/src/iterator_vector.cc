#include <vector>
#include <iostream>
#include <limits>
#include <string>

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

    for(std::vector<double>::iterator iter = std::begin(doubleVector); iter != end(doubleVector); ++iter)
    {
        *iter /= max;
        std::cout<<*iter<<" ";
    }

    std::vector<std::string> stringVector(10, "hello");
    for(auto& str : stringVector)
    {
        str.append(" there");
    }

    /*const iterator 관련 const 붙이면 더 안정적이니까*/
    // 이러면 된다고 한다. c begin이랑 cend로 붙이면 된다고 함
    for(auto it = std::cbegin(stringVector); it != std::cend(stringVector); ++it)
    {
        std::cout<<*it<<std::endl;
    }

    //또는
    for(const auto element: stringVector)
    {
        std::cout<<element<<std::endl;
    }

    /*
    이럼 안된다는 걸 보여줌
    std::vector<int> intVector;
    auto iter = std::end(intVector);
    *iter = 10; -> 요기서 end()가 리턴하는 반복자는 vector의 마지막 원소가 아닌 그 다음 원소를 가리킨다. 따라서 end()의 리턴 값을 역참조하면 예상과 다른 결과가 나온다.
    */

    std::vector<int> intVector(10);
    auto it = begin(intVector);
    it+=3;
    --it;
    *it = 4;

    for(auto iter = std::cbegin(intVector); iter != std::cend(intVector); ++iter)
    {
        std::cout<<*iter<<std::endl;
    }


    return 0;
}