#include <iostream>
#include <string>

using namespace std;

void mysteryFunction(const std::string* someString)
{
    cout << *someString << endl;
}

void printString(const std::string& myString)
{
    cout << myString << endl;
}

int main()
{
    std::string myString = "the string";
    mysteryFunction(&myString);

    std::string someString = "Hello World";
    printString(someString);
    printString("Hello World");
    
    return 0;
}