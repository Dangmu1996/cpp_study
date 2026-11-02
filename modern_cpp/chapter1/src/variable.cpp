#include <iostream>

using namespace std;

int main()
{
    int uninitializedInt;
    int initializedInt = 7;

    cout <<uninitializedInt << "is random value" << endl;
    cout << initializedInt << " was assigned an initial value" << endl;

    float myFloat = 3.14f;
    int i1 = (int)myFloat;
    int i2 = int(myFloat);
    int i3 = static_cast<int>(myFloat);

    int someInteger = 256;
    short someShort;
    long someLong;
    float someFloat;
    double someDouble;

    someInteger++;
    someInteger +=2;
    someShort = static_cast<short>(someInteger);
    someLong = someShort + 100000;
    someFloat = someLong + 0.785f;
    someDouble = static_cast<double>(someFloat) / 100000;
    cout << someDouble << endl;

    return 0;
}