#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
    fstream ioData(filename.data());
    if(!ioData)
    {
        cerr<<"Error while opening file " <<filename <<endl;
        return false;
    }

    //파일 끝까지 반복한다.
    while(ioData)
    {
        int idRead;
        string number;

        while(ioData)
        {
            int idRead;
            string number;

            ioData>>idRead;
            if(!ioData)
            {
                break;
            }

            if(idRead == id)
            {
                //쓰기 위치를 현재 읽기 위치로 이동한다.
                ioData.seekp(ioData.tellg());
                //한 칸 띄운 뒤 새 번호로 쓴다.
                ioData << " " <<newNumber;
                break;
            }
            // 현재 위치에서 숫자를 읽어서 스트림의 위치를 다음 레코드로 이동한다.
            ioData>>number;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    string name = "../data/serial.txt";
    changeNumberForID(name, 123, "123-456-789");

    return 0;
}