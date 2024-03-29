#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    regex reg("[\\w]+");
    while(true){
        cout<<"Enter a string to split (q=quit): ";
        string str;
        if(!getline(cin, str) || str == "q")
            break;
        
        const sregex_iterator end;
        for(sregex_iterator iter(cbegin(str), cend(str), reg);
            iter != end; ++iter){
                cout <<"\""<<(*iter)[0]<<"\""<<endl;
            }

    }

    return 0;
}