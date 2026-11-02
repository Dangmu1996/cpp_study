#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    /*Intptr을 int 포인터로 지정*/
    using IntPtr = int *;

    int *p1;
    IntPtr p2;

    p1=p2;
    p2=p1;

    cout<<"p1: " << p1 <<", p2: "<<p2 <<endl;


    return 0;
}