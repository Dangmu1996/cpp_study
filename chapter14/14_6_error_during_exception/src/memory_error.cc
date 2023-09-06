#include <new>
#include <limits>
#include <exception>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int *ptr = nullptr;
    size_t intergerCount = numeric_limits<size_t>::max();
    try
    {
        ptr = new int[intergerCount];
    }
    catch(const bad_alloc& e)
    {
        cerr<<__FILE__<<"("<<__LINE__<<"): Unable to allocate memory: "<<e.what()<<endl;
        //메모리 할당 에러를 처리한다.
        return 1;
    }

    delete[] ptr;
    ptr = nullptr;


    return 0;
}