#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int *myIntegerPointer;
    myIntegerPointer = new int;
    *myIntegerPointer = 8;
    
    cout << *myIntegerPointer << ", " << myIntegerPointer << endl;

    delete myIntegerPointer;
    myIntegerPointer = nullptr;

    int i = 9;
    int *myIntegerPointer_2 = &i;

    cout << *myIntegerPointer_2 << ", " << myIntegerPointer_2 << endl;

    int arraySize = 8;
    int* myVariableSizedArray = new int[arraySize];
    myVariableSizedArray[3] =2;
    delete[] myVariableSizedArray;
    myVariableSizedArray = nullptr;

    
    return 0;
}