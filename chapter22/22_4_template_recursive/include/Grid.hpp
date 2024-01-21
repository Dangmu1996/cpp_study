#pragma once
#include <vector>

template <typename T>
class OneDGrid
{
public:
    explicit OneDGrid(std::size_t size = kDefaultSize);
    virtual ~OneDGrid() = default;

    T& operator[](std::size_t x);
    const T& operator[](std::size_t x) const;

    void resize(std::size_t newSize);
    std::size_t getSize() const { return mElements.size();}

    static const std::size_t kDefaultSize = 10;
private:
    std::vector<T> mElements;
};

template <typename T>
OneDGrid<T>::OneDGrid(std::size_t size)
{
    resize(size);
}

template <typename T>
void OneDGrid<T>::resize(std::size_t newSize)
{
    mElements.resize(newSize);
}

template <typename T>
T& OneDGrid<T>::operator[](std::size_t x)
{
    return mElements[x];
}

template <typename T>
const T& OneDGrid<T>::operator[](std::size_t x) const
{
    return mElements[x];
}