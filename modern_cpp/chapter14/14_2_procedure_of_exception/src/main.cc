#include <vector>
#include <string_view>
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
    ifstream inputStream(fileName.data());
    if(inputStream.fail())
    {
        //파일 열기 실패: 익셉션을 던진다.
        // throw exception();
        // int 형으로 해도 된다.
        throw 5;
    }

    // 파일에 담긴 정숫값을 하나씩 읽어서 벡터에 추가한다.
    vector<int> integers;
    int temp;
    while(inputStream >> temp)
    {
        integers.push_back(temp);
    }
    return integers;
}

int main(int argc, char **argv)
{
    const string fileName = "../data/IntegerFile.txt";
    
    vector<int> myInts;
    try
    {
        myInts= readIntegerFile(fileName);
    }
    catch(int e)//catch(const exception& e)
    {
        // cerr << "Unalbe to open file "<<fileName<<endl;
        cerr << "Unable to open file "<<fileName<<" ("<<e<<")"<<endl;
        return 1;
    }
    for(const auto& element: myInts)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    
    return 0;
}