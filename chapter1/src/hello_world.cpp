#include <iostream>
#include "namespace.h"

void mycode::foo()
{
    std::cout<<"foo() called in the mycode namespace" << std::endl;
}

int main()
{
    std::cout << "hello world!" << std::endl;
    mycode::foo();
    return 0;
}