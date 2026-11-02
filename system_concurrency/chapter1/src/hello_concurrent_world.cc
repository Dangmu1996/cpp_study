#include <thread>
#include <iostream>

void hello()
{
    std::cout<<"Hello Conncurrent World \n";
}

int main()
{
    std::thread t(hello);
    t.join();
    return 0;
}