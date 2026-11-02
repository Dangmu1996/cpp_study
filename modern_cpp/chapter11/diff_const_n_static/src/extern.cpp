#include <iostream>


extern int x;  //정의가 아니라 선언문이 됨 어쨋든 외부 링크가 되는 것임

int main()
{

    std::cout<<x<<std::endl;
}