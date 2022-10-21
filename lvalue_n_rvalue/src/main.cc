#include <iostream>

using namespace std;

void handleMessage(std::string& message)
{
    cout<<"handleMessage wit lvalue reference: "<<message<<endl;
}

void handleMessage(std::string&& message)
{
    message=message+"1";
    cout<<"handleMessage wit rvalue reference: "<<message<<endl;
}

int main(int argc, char ** argv)
{
    string a="123";
    string b="456";

    handleMessage(a);
    handleMessage(a+b);
    
    return 0;
}
