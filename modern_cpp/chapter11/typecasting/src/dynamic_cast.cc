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
    Base *b;
    Derived *d=new Derived();

    b=d; //  up casting은 상관없음
    d=dynamic_cast<Derived*>(b); // downcasting 할때 필요

    Base base;
    Derived derived;
    Base& br=derived;
    try  // 이상한거 하면  exception 발생
    {
        Derived& dr = dynamic_cast<Derived&>(br);    
    }
    catch(const bad_cast&)
    {
        cout<<"Bad cast!"<<endl;
    }
    
    

    return 0;
}