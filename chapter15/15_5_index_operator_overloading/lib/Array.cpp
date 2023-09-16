#include "Array.hpp"

template <typename T> Array<T>::Array()
{
    mSize = kAllocSize;
    mElements = new T[mSize] {}; //원소를 0으로 초기화한다.
}

template <typename T> Array<T>::~Array()
{
    delete [] mElements;
    mElements = nullptr;
}

template <typename T> void Array<T>::resize(size_t newSize)
{
    // 더 큰 배열을 생성한다. 값은 0으로 초기화한다.
    auto newArray = std::make_unique<T[]>(newSize);

    // 새로 생성할 배열은 반드시 이전(mSize) 보다 커야 한다.
    for(size_t i = 0; i < mSize ; i++)
    {
        //이전 배열의 원소를 모두 새 배열로 복사한다.
        newArray[i] = mElements[i];
    }

    // 이전 배열을 삭제하고 새 배열을 설정한다.
    delete[] mElements;
    mSize = newSize;
    mElements = newArray.release();
}

template <typename T> const T& Array<T>::getElementAt(size_t x) const
{
    if( x >= mSize)
    {
        throw std::out_of_range("");
    }
    return mElements[x];
}

template <typename T> void Array<T>::setElementAt(size_t x, const T& val)
{
    if ( x >= mSize)
    {
        // 클라이언트가 요청한 원소 뒤로 kAllocSize 만큼 공간을 할당한다.
        resize(x + kAllocSize);
    }
    mElements[x] = val;
}

template <typename T> size_t Array<T>::getSize() const
{
    return mSize;
}

template <typename T>
T& Array<T>::operator[] (size_t x)
{
    if (x>=mSize)
    {
        resize(x+kAllocSize);
    }

    return mElements[x];
}

template <typename T>
const T& Array<T>::operator[](size_t x) const
{
    if (x>=mSize)
    {
        //위에는 out_of ragne 익셉션
        throw std::out_of_range("");
        
        //아래는 nullptr return
        // static T nullValue = T();
        // return nullValue;
    }
    return mElements[x];
}