#include "FileOpenError.hpp"
#include "FileReadError.hpp"
#include <vector>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
    ifstream inputStream(fileName.data());
    if(inputStream.fail())
    {
        //파일 열기에 실패한 경우 익셉션을 던진다.
        throw FileOpenError(fileName);
    }

    vector<int> integers;
    size_t lineNumber =0;
    while(!inputStream.eof())
    {
        //파일에서 한 줄을 읽는다.
        string line;
        getline(inputStream, line);
        ++lineNumber;

        //방금 읽은 한 줄에 대한 스트링 스트림을 생성한다.
        istringstream lineStream(line);

        //파일에서 정수를 하나씩 읽어 벡터에 추가한다.
        int temp;
        while(lineStream >> temp)
        {
            integers.push_back(temp);
        }

        if(!lineStream.eof())
        {
            //스트링 스트림의 끝에 도달하지 않았다.
            //다시 말해 한 줄을 읽는 도중에 에러가 발생했다.
            //따라서 익셉션을 던진다.
            throw FileReadError(fileName, lineNumber);
        }
    }
    return integers;
}

int main(int argc, char **argv)
{
    const string fileName = "../data/IntegerFile.txt";
    
    vector<int> myInts;
    try
    {
        myInts = readIntegerFile(fileName);
    }
    catch(const FileError& e)
    {
        cerr << e.what() <<endl;
        return 1;
    }

    return 0;
}