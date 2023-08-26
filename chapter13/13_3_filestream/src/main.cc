#include <fstream>
#include <iostream>

using namespace std;

/*
ios_base::app 파일을 열고,쓰기 연산을 수행하기 전에 파일끝으로 간다.
ios_base::ate 파일을 엵고, 즉시 파일 끝으로 간다.
ios_base::binary 입력 또는 출력을 테스트가 아닌 바이너리 모드로 처리한다.
ios_base::in 입력할 파일을 열고 시작 지점부터 읽는다.
ios_base::out 출력할 파일을 열고 시작 지점부터 쓴다. 기존 데이터를 덥어쓴다.
ios_base::trunc 출력할 파일을 열고 기존 데이터를 모두 삭제한다(truncate)
*/

int main(int argc, char **argv)
{   
    ofstream outFile("../data/test.txt", ios_base::trunc);
    if(!outFile.good())
    {
        cerr<<"Error while opening output file!"<<endl;
        return -1;
    }

    outFile <<"There were "<<argc<<" arguments to this program."<<endl;
    outFile <<"They are: "<<endl;
    for(int i=0; i<argc; i++)
    {
        outFile<<argv[i]<<endl;
    }
    return 0;
}