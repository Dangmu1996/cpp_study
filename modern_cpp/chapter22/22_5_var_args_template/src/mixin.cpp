#include "Mixin.hpp"

int main()
{
    MyClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
    a.Mixin1Func();
    a.Mixin2Func();

    MyClass<Mixin1> b(Mixin1(33));
    b.Mixin1Func();

    return 0;
}