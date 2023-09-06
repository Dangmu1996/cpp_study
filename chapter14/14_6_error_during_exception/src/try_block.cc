#include <stdexcept>
#include <iostream>
#include <exception>
/*
 생성자 이니셜라이저에서 던진 익셉션을 다른 익셉션으로 변환 할 때
 메시지를 로그 파일에 기록할 때
 생성자 이니셜라이저에서 할당한, 소멸자로 자동 제거할 수 없는 리소스를 익셉션을 던지기 전에 해제할 때
*/

class SubObject
{
    public:
        SubObject(int i)
        {
            throw std::runtime_error("Exception by SubObject ctor");
        }
};


class MyClass
{
    public:
        MyClass()
        try
            : mData(new int[42]{1, 2, 3}), mSubObject(42)
        {
            /* code */
        }
        catch(const std::exception& e)
        {
            // 메모리 정리
            delete[] mData;
            mData = nullptr;
            std::cout<<"function-try-black caught: '"<<e.what()<<"'"<<std::endl;
        }
    private:
        int *mData=nullptr;
        SubObject mSubObject;
};

int main()
{
    try
    {
        MyClass m;
    }
    catch(const std::exception& e)
    {
        std::cout<<"main() cuaght: "<<e.what()<<"'"<<std::endl;
    }

    return 0;
}