#include <string>
#include <memory>
#include <iostream>
#include <exception>
#include <fstream>

using namespace std;

void funcOne();
void funcTwo();

int main(int argc, char **argv)
{
    // unused parameter warning 안받으려고
    (void) argc;
    (void) argv;
    try
    {
        funcOne();
    }
    catch(const exception &e)
    {
        cerr<<"Exception caught!" <<endl;
        return 1;
    }
    return 0;
}

void funcOne()
{
    string str1;
    // string* str2 = new string(); 이딴 식으로 사용하면 exception 발생하면서 delete 안되서 memory 누수 발생함
    auto str2 = make_unique<string>("hello");  // smart 포인터 사용 하는게 제일 좋은 것 같음.
    funcTwo();
    //delete str2;
}

void funcTwo()
{
    ifstream fileStream;
    fileStream.open("../data/data.txt");
    throw exception();
    fileStream.close(); //얘는 다행히 소멸자에서 알아서 close 해 준다함.
}