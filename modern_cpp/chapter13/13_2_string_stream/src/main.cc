#include "Muffin.hpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Muffin createMuffin(istringstream& stream)
{
    Muffin muffin;
    string description;
    int size;
    bool hasChips;

    //세 값 모두 읽는다. 이때 chips는 "true"나 "false"란 스트링으로 표현한다.
    stream >> description >>size >> boolalpha >>hasChips;
    if(stream) // 읽기 연산 성공
    {
        muffin.setSize(size);
        muffin.setDescription(description);
        muffin.setHasChocolateChips(hasChips);
    }


    return muffin;
}

int main(int argc, char **argv)
{
    Muffin a;
    string b("changmin 5 true");
    istringstream my_stream(b);
    a=createMuffin(my_stream);
    a.output();
    return 0;
}