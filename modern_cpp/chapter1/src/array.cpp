#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    int myArray[3] = {0};
    for (const auto &i : myArray)
    {
        std::cout << i << std::endl;
    } 

    unsigned int arraySize = std::size(myArray);
    std::cout << arraySize << std::endl;

    std::array<int, 3> arr = {9,8,7};
    std::cout << "Array size = " << arr.size() << std::endl;
    std::cout << "2nd element = " << arr[1] << std::endl;

    vector<int> myVector = {11, 22};

    myVector.push_back(33);
    myVector.push_back(44);
    cout << "1st element: " << myVector[0] << endl;

    return 0;
}