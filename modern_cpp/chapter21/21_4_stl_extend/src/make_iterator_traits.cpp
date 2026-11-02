#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

template<typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
    typename std::iterator_traits<IteratorType>::value_type temp;
    temp = *it;
    cout << temp <<endl;
}

int main()
{
    vector<int> v{ 5 };
    iteratorTraitsTest(cbegin(v));
    
    return 0;
}