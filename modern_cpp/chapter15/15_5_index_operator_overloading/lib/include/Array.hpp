#pragma once

#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
public:
    // 필요에 따라 크기가 증가하는 배열을 디폴트 크기로 생성한다.
    Array();
    virtual ~Array();

    // 대입과 값 전달 방식을 허용하지 않는다.
    Array<T>& operator=(const Array<T>& rhs) = delete;
    Array(const Array<T>& src) = delete;

    // 인덱스 x에 있는 값을 리턴한다. 인덱스 x에 원소가 없으면 
    // out_of_range 익셉션을 던진다.
    const T& getElementAt(size_t x) const;

    // 인덱스 x에 값을 설정한다. 인덱스 x가 현재 배열의 크기를 벗어나면 
    // 공간을 더 할당ㅎ나다.
    void setElementAt(size_t x, const T& value);

    size_t getSize() const;

    T& operator[](size_t x);
    const T& operator[](size_t x) const; //const 레퍼런스를 리턴하게 하면 읽기 전용 operator []가 만들어짐 근데 return 값으로 오버로딩은 하면 안되니 메서드 전체도 const로 지정한다.
private:
    static const size_t kAllocSize = 4;
    void resize(size_t newSize);
    T* mElements = nullptr;
    size_t mSize = 0;
};

template class Array<int>;
