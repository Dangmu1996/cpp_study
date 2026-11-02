#include <iostream>
#include <memory>

using namespace std;


int main(void)
{
    /*prevent from changing value*/
    const int *a;  // same as int const* a
    a=new int[10];
    a[4]=5; //error

    delete []a;
    a=nullptr;

    /*prevent from changing itself */
    int* const b=nullptr;
    b=new int[10]; //error

    /*prevent from changing itself and value*/
    int const* const ip=nullptr; // same as const int *const ip=nullptr


  return 0;
}