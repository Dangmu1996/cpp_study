#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    regex r("//\\s*(.+)$");
    while(true){
        cout << "Enter a string (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q")
            break;
        
        smatch m;
        if(regex_search(str, m, r))
            cout << " Found comment '"<< m[1]<<"'"<<endl;
        else
            cout << " Np comment found!"<<endl;
    }

    return 0;
}