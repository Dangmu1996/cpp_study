#include <iostream>
#include <memory>

using namespace std;


int main(void)
{
    /*prevent from changing value*/
    int a;
    const int & aref=a;

    aref=4;

  return 0;
}