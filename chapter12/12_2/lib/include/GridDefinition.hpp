#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <optional>
#include <stdexcept>


template <typename T>
Grid<T>::Grid(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for (auto& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
    if(x>mWidth || y>=mHeight)
    {
        throw std::out_of_range("");
    }
}

template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template<typename T>
std::optional<T> &Grid<T>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x,y));
}

/*이렇게 하면 int, double vector<int> 에만 인스턴스화 된다고 한다.*/
//template class Grid<int>;
//template class Grid<double>;
//template class Grid<std::vector<int>>;
