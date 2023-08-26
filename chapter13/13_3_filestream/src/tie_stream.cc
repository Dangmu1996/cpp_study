#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{   
    ifstream inFile("../data/input.txt"); // 주의 : input.txt가 반드시 있어야 한다.
    ofstream outFile("../data/output.txt");

    //inFile과 outFile을 연결한다.
    inFile.tie(&outFile);

    //outFile에 텍스트를 쓴다. std::endl이 입력되기 전까지는 내보내지 않는다.
    outFile<<"Hello there!";
    //outFileㅇ을 아직 내보내지 않은 상태다

    //inFile에서 텍스트를 읽는다. 그러면 outFile에 대해 flush()가 호출된다.
    string nextToken;
    inFile >> nextToken;
    //이제 outFile이 내보내졌다.

    return 0;
}