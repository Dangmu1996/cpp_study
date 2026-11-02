#include <iostream>
#include <stdexcept>

using namespace std;

double SafeDivide(double num, double den)
{
    if(den == 0)
    {
        throw invalid_argument("Divide by zero");
    }
    return num/den;
}

int main(int argc, char **argv)
{
    try
    {
        cout<<SafeDivide(5, 2)<<endl;
        cout<<SafeDivide(10, 0)<<endl;
        cout<<SafeDivide(3, 3)<<endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Caughe exception: "<<e.what()<<endl;
    }
    

    return 0;
}