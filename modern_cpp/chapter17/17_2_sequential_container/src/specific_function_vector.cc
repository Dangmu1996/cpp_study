#include <vector>
#include <string>
#include <memory>

class Element
{
    public:
        Element()
        {}
        virtual ~Element()=default;

};

int main()
{
    std::vector<int> intVector(10, 100); //초깃값이 100인 int 원소 열개를 담은 vector 생성
    std::vector<std::string> stringVector(10, "hello");

    std::vector<Element> elementVector;

    std::vector<int> intVector0({1, 2, 3, 4, 5, 6});
    std::vector<int> intVector1 ={1, 2, 3, 4, 5, 6};
    std::vector<int> intVector2{1, 2, 3, 4, 5, 6};

    auto elementVector1 = std::make_unique<std::vector<Element>>(10);

    return 0;
}