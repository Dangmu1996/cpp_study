#include <iostream>

int func(int param1, [[maybe_unused]] int param2)
{
    return 42;
}

int main()
{
    func(1,3);
    return 0;
}