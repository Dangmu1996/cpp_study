#include <iostream>
#include <memory>

class Demo
{
    public:
        static int get(){return 5;}

};

int get(){
    return 10;
}

namespace NS
{
    int get(){return 20;}
}

int main()
{
    auto pd = std::make_unique<Demo>();
    Demo d;
    std::cout<<pd->get()<<std::endl;
    std::cout<<d.get()<<std::endl;
    std::cout<<NS::get()<<std::endl;
    std::cout<<Demo::get()<<std::endl;
    std::cout<<::get()<<std::endl;
    std::cout<<get()<<std::endl;
    return 0;
}