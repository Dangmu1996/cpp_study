#include <exception>
#include <iostream>

using namespace std;

void g()
{
    throw invalid_argument("Some exception");
}

void f()
{
    try
    {
        g();
    }
    catch(const exception& e)
    {
        cout<<"caught in f: "<<e.what() <<endl;
        throw; // 다시 던지기
    }
}

int main()
{
    try
    {
        f();
    }
    catch(const invalid_argument& e)
    {
        cout<<"invalid_argument caught in main: " <<e.what() <<endl;
    }
    catch(const exception& e)
    {
        cout<<"exception caught in main: "<<e.what()<<endl;
    }

    return 0;
}