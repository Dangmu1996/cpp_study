#include <iostream>
#include <complex>

std::complex<long double> operator"" _i(const char*p)
{
    int d=std::stoi(p);
    return std::complex<long double>(0, d);
}

int main(int argc, char ** argv)
{
    auto com=123_i;

    std::cout<<com<<std::endl;
    return 0;
}