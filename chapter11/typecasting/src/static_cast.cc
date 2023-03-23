#include <iostream>

using namespace std;

class Base
{
    public : 
        virtual ~Base()=default;
};

class Derived : public Base
{
    public : 
        virtual ~Derived() =default;
};

int main()
{
    int i=3, j =4;
    double result = static_cast<double>(i)/j;

    Base *b;
    Derived *d=new Derived();

    b=d; //  up casting은 상관없음
    d=static_cast<Derived*>(b); // downcasting 할때 필요

    Base base;
    Derived derived;
    Base& br=derived;
    Derived& dr = static_cast<Derived&>(br);

    return 0;
}