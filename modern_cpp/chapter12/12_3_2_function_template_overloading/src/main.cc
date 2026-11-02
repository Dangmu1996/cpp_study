#include <iostream>
#include <string.h>

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
    for(size_t i =0; i<size; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return NOT_FOUND;
}


template<> // 매개변수 타입을 인수로부터 추론 할 수 있다면 template <const char*>를 생략해도 된다
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
    for(size_t i =0; i<size; i++)
    {
        if(strcmp(arr[i], value)==0)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

// 이 부분이 그냥 함수로 오버로딩 한 거입
size_t Find(const char* const& value, const char* const* arr, size_t size)
{
    for(size_t i=0; i<size; i++)
    {
        if(strcmp(arr[i], value)== 0)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

int main(int argc, char ** argv)
{
    const char* word = "two";
    const char* words[] = {"one", "two", "three", "four"};
    const size_t sizeWords = std::size(words);
    size_t res;
    //const char* 로 특수화된 템플릿 버전을 호출한다.
    res = Find<const char*>(word, words, sizeWords);
    res = Find(word, words, sizeWords); // 비템플릿(일반) Find() 호출




    return 0;
}
