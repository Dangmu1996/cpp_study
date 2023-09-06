#pragma once

#include <Element.hpp>
#include <exception>

template <typename T>
class Matrix
{
    public:
        Matrix(size_t width, size_t height);
        virtual ~Matrix();
    private:
        void cleanup();

        size_t mWidth = 0;
        size_t mHeight = 0;
        T** mMatrix = nullptr;
};