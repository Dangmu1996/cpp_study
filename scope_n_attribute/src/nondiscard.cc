#include <iostream>

[[nodiscard]] int func()
{
    return 42;
}

int main()
{
    func();
    return 0;
}