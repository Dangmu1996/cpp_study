#pragma once
#include <iostream>

template <typename T>
class Pointer
{
    public:
        Pointer(T* ptr);
        virtual ~Pointer();

        //대입과 값 전달 방식을 허용하지 않는다.
        Pointer(const Pointer<T>& src) = delete;
        Pointer<T>& operator=(const Pointer<T>& rhs) = delete;

        //여기에 역참조 연산자를 적는다.
        T& operator*();
        const T& operator*() const;

        T* operator->();
        const T* operator->() const;

        operator void*() const;
        // operator bool() const;

        // friend bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs);
    private:
        T* mPtr = nullptr;
};

template <typename T>
Pointer<T>::Pointer(T* ptr) : mPtr(ptr)
{
}

template <typename T>
Pointer<T>::~Pointer()
{
    delete mPtr;
    std::cout<<"destructor called"<<std::endl;
    mPtr = nullptr;
}

template <typename T>
T& Pointer<T>::operator*()
{
    return *mPtr;
}

template <typename T>
const T& Pointer<T>::operator*() const
{
    return *mPtr;
}

template <typename T>
T* Pointer<T>::operator->()
{
    return mPtr;
}

template <typename T>
const T* Pointer<T>::operator->() const
{
    return mPtr;
}

template <typename T>
Pointer<T>::operator void*() const
{
    return mPtr;
}


/* 이것 보단 걍void *() 가 좋다고 함*/
// template <typename T>
// Pointer<T>::operator bool() const
// {
//     return mPtr!=nullptr;
// }

// template <typename T>
// bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs)
// {
//     return lhs.mPtr != rhs;
// }