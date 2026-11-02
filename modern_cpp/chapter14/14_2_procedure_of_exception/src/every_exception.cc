#include <vector>
#include <string_view>
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
    ifstream inputStream(fileName.data());
    if(inputStream.fail())
    {
        //파일 열기에 실패한 경우: 익셉션을 던진다.
        throw invalid_argument("Unalbe to open the file.");
    }

    // 파일에 담긴 정숫값을 하나씩 읽어서 벡터에 추가한다.
    vector<int> integers;
    int temp;
    while(inputStream >> temp)
    {
        integers.push_back(temp);
    }

    if(!inputStream.eof())
    {
        // 파일 끝(EOF)에 도달하지 않았다.
        // 다시 말해 파일을 읽는 도중에 에러가 발생했다.
        // 따라서 익셉션을 던진다.
        throw runtime_error("Error reading the file.");
    }
    return integers;
}

int main(int argc, char **argv)
{
    const string fileName = "../data/IntegerFile2.txt";
    
    vector<int> myInts;
    try
    {
        myInts= readIntegerFile(fileName);
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what()<<endl;
        return 1;
    }
    catch(const runtime_error& e)
    {
        cerr << e.what() <<endl;
        return 2;
    }
    catch(...)
    {
        cerr << "some other exception "<<fileName<<endl;
        return 1;
    }
    
    for(const auto& element: myInts)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    
    return 0;
}