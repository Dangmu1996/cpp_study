#include <random>
#include <iostream>

using namespace std;

int main()
{
    random_device rnd;

    cout<<"Entorpy: " << rnd.entropy() << endl;
    cout<<"Min value: "<< rnd.min()
        << ", Max value: "<< rnd.max() << endl;
    
    cout<<"Random number: " << rnd() <<endl;
    return 0;
} 