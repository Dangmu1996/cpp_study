#include <iostream>

void myFunction(int i, char c );

void myFunction(int i , char c)
{
    std::cout << " the value of i is " << i << std::endl;
    std::cout << " the value of c is " << c << std::endl;
}

int main()
{

    int someInt;
    char someChar;
    myFunction(8, 'a');
    myFunction(someInt, 'b');
    myFunction(5, someChar);

    return 0;
}