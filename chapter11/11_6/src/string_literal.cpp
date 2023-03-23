#include <iostream>
#include <string>

std::string operator"" _s(const char* str, size_t len)
{
    std::cout<<len<<std::endl;
    return std::string(str, len);
}

int main(int argc, char ** argv)
{
    std::string str1="Hello World"_s;
    auto str2= "Hello dangmu"_s;
    auto str3= "Hello literal";

    std::cout<<str1<<std::endl;
    std::cout<<str2<<std::endl;
    std::cout<<str3<<std::endl;
    return 0;
}