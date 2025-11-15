#include <iostream>

using namespace std;

int main()
{
    struct Point { double mX , mY, mZ;};
    Point point;
    point.mX = 1.0; point.mY = 2.0; point.mZ = 3.0;
    auto[x, y, z] = point;
    cout << x << y << z << endl;

    return 0;
}