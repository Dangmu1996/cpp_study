#pragma once
#include <vector>

template <typename T, std::size_t N>
class NDGrid
{
public:
    explicit NDGrid(std::size_t size = kDefaultSize);
    virtual ~NDGrid() = default;

    NDGrid<T, N-1>& operator[](std::size_t x);
    const NDGrid<T, N-1>& operator[](std::size_t x) const;

    void resize(std::size_t newSize);
    std::size_t getSize() const { return mElements.size(); }

    static const std::size_t kDefaultSize = 10;
private:
    std::vector<NDGrid<T, N-1>> mElements;
};

template <typename T>
class NDGrid<T, 1>
{
public:
    explicit NDGrid(std::size_t size = kDefaultSize);
    virtual ~NDGrid() = default;

    T& operator[](std::size_t x);
    const T& operator[](std::size_t x) const;

    void resize(std::size_t newSize);
    std::size_t getSize() const { return mElements.size(); }

    static const std::size_t kDefaultSize = 10;
private:
    std::vector<T> mElements;
};

template <typename T, std::size_t N>
NDGrid<T, N>::NDGrid(std::size_t size)
{
    resize(size);
}

template <typename T, std::size_t N>
void NDGrid<T, N>::resize(std::size_t newSize)
{
    mElements.resize(newSize);
    // vector에 대해 resize()를 호출하면, NDGrid<T, N-1> 원소에 대한 영인수 생성자를
    // 호출해서 디폴트 크기로 원소가 생성된다. 따라서 각 원소마다 명시적으로
    // resize()를 재귀 호출하는 방식으로 중첩된 Grid 원소의 크기를 조정한다.
    for(auto & element : mElements){
        element.resize(newSize);
    }
}

template <typename T, std::size_t N>
NDGrid<T, N-1>& NDGrid<T, N>::operator[](std::size_t x)
{
    return mElements[x];
}

template <typename T, std::size_t N>
const NDGrid<T, N-1>& NDGrid<T, N>::operator[](std::size_t x) const
{
    return mElements[x];
}

template <typename T>
NDGrid<T, 1>::NDGrid(std::size_t size)
{
    resize(size);
}

template <typename T>
void NDGrid<T, 1>::resize(std::size_t newSize)
{
    mElements.resize(newSize);
}

template <typename T>
T& NDGrid<T, 1>::operator[](std::size_t x)
{
    return mElements[x];
}

template <typename T>
const T& NDGrid<T, 1>::operator[](std::size_t x) const
{
    return mElements[x];
}