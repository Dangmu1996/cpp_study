#include "Matrix.hpp"
#include <new>
#include <iostream>

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
{
    mMatrix = new T*[width]{}; //배열을 영으로 초기화한다.

    // mWidth와 mHeight 멤버를 생성자 이니셜라이저로 초기화 하면 안 된다.
    // 앞에 나온 mMatirx를 성공적으로 할당했을때만 초기화해야 하기 때문이다.
    mWidth = width;
    mHeight = height;

    try
    {
        for(size_t i =0; i<width; ++i)
        {
            mMatrix[i] = new T[height];
        }
    }
    catch(...)
    {
        std::cerr<<"Exception cautght in constructor, cleaning up..."<<std::endl;
        cleanup();
        std::throw_with_nested(std::bad_alloc());
    }
    

}

template <typename T>
Matrix<T>::~Matrix()
{
    cleanup();
}

template <typename T>
void Matrix<T>::cleanup()
{
    for(size_t i=0; i<mWidth; ++i)
    {
        delete[] mMatrix[i];
    }
    delete[] mMatrix;
    mMatrix=nullptr;
    mWidth=mHeight=0;
}

template class Matrix<Element>;