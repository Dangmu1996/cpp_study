#include <iostream>

using namespace std;

void a(void)
{
    static int b=1;
    b+=1;
    cout<<b<<endl;
}

int main(void)
{
    for(int i=0; i<10; i++)
    {
        a();
    }

    return 0;
}