#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3};
    cout<<size(vec)<<endl;
    cout<<empty(vec)<<endl;
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;

    int *data1 = vec.data();
    int *data2 = data(vec);

    cout<<data1<<endl;
    cout<<data2<<endl;
    return 0;
}