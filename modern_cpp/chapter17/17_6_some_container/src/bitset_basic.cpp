#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bitset<10> myBitset;

    myBitset.set(3);
    myBitset.set(6);
    myBitset[8] = true;
    myBitset[9] = myBitset[3];

    if(myBitset.test(3))
    {
        cout<<"Bit 3 is set!"<<endl;
    }

    cout<<myBitset<<endl;

    auto str1 = "0011001100";
    auto str2 = "0000111100";
    bitset<10> bitsOne(str1);
    bitset<10> bitsTwo(str2);

    auto bitsThree = bitsOne & bitsTwo;
    cout<<bitsThree<<endl;
    bitsThree<<=4;
    cout<<bitsThree<<endl;

    return 0;
}