#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

vector<int> createVectorOfSize(size_t size)
{
    vector<int> vec(size);
    int contents =0;
    for(auto& i : vec)
    {
        i = contents++;
    }    
    return vec; //이동 의미론 덕분에 표준 라이브러리 컨테이너를 함수에서 값으로 리턴해도 성능 오버헤드를 최소화 할 수 있다.
}

int main()
{
    vector<int> myVector;
    myVector = createVectorOfSize(123); // 이동 대입 연산자가 호출된다. 복제 연산 x

    vector<string> vec;
    string myElement(5, 'a'); //"aaaaa"란 스트링을 만든다
    vec.push_back(myElement); // 이렇게 하면 복제본을 만들어서 vector에 추가한다. why? lvaule 니까

    vec.push_back(std::move(myElement)); 
    // 이렇게 rvlaue로 만들면 복제 연산 발생하지 않음 근데 이럼 myElement값은 유효하지만 상태가 불분명함
    // clear를 호출하거나 다른 작업으로 상태를 명확히 설정하기 전까지는 myElement 를 더 잇아 사용하면 안된다.
    


    return 0;
}