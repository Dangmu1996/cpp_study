#include <fstream>
#include <iostream>

using namespace std;

/*
1. "12345"란 스트림을 파일에 출력한다.
2. 스트림의 현재 위치가 5인지 확인한다.
3. 출력 스트림의 위치를 2로 옮긴다.
4. 위치가 2인 지점에서 0을 쓴 뒤 출력 스트림을 닫느다.
5. test.out 파일에 대한 입력 스트림을 연다.
6. 첫 번재 토큰을 정수 타입의 값으로 읽는다.
7. 읽은 값이 12045인지 확인한다.
*/

int main(int argc, char **argv)
{   
    ofstream fout("../data/test.out");
    if(!fout)
    {
        cerr<<"Error opening test.out for writing"<<endl;
        return 1;
    }

    //1. "12345"란 스트림을 파일에 출력ㅎ나다.
    fout<<"12345";

    //2. 스트림의 현재 위치가 5인지 확인한다.
    streampos cur_pos = fout.tellp();
    if(5==cur_pos)
    {
        cout<<"Test passed: Currently at position 5"<<endl;
    }
    else
    {
        cout<<"Test filaed: Not at position 5"<<endl;
    }

    //3. 출력 스트림의 위치를 2로 옮긴다.
    fout.seekp(2, ios_base::beg);

    //4. 위치가 2인 지점에 0을 쓴 뒤 스트림을 닫느다.
    fout << 0;
    fout.close();

    //5. test.out에 대한 입력 스트림을 연다.
    ifstream fin("../data/test.out");
    if(!fin)
    {
        cerr<<"Error reading from file"<<endl;
        return 1;
    }

    //6. 첫 번째 토큰을 정수 타입의 값으로 읽는다.
    int testVal;
    fin >> testVal;
    if(!fin)
    {
        cerr<<"Errror reading from file"<<endl;
        return 1;
    }

    //7. 읽은 값이 12045인지 확인한다.
    const int expected = 12045;
    if(testVal == expected)
    {
        cout<<"Test passed: Value is "<<expected<<endl;
    }
    else
    {
        cout<<"Test failed: Vaule is not "<<expected<<" (it was" << testVal <<")"<<endl;
    }

    
    return 0;
}