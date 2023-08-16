#include <iostream>

template <typename T>
constexpr T pi = T(3.14159265358979323848626);

int main(int argc, char **argv)
{
    float piFloat = pi<float>;
    long double piLondDouble = pi<long double>;


    return 0;
}