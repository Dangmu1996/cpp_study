#pragma once
#include "Grid.hpp"

#include <optional>
#include <string>
#include <vector>

/*이렇게 하면 const char* 형태를 string으로 변환해서 사용함*/
template<>
class Grid<const char*>
{
public:
    //explicit은 형변환을 자동적으로 하는 것을 막아주는 것이라고 한다.
    explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    virtual ~Grid() = default;

    //복제생성자와 대입 연산자를 명시적으로 디폴트로 선언한다. 얇은 복사를 한다.
    Grid(const Grid &src) = default;
    Grid<const char*>& operator=(const Grid& rhs) = default;

    std::optional<std::string>& at(size_t x, size_t y);
    const std::optional<std::string>& at(size_t x, size_t y) const;

    size_t getHeight() const{return mHeight;}
    size_t getWidth() const{return mWidth;}

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    
    std::vector<std::vector<std::optional<std::string>>> mCells;
    size_t mWidth, mHeight;
};


Grid<const char*>::Grid(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for(auto& column : mCells)
    {
        column.resize(mHeight);
    }
}

void Grid<const char*>::verifyCoordinate(size_t x, size_t y) const
{
    if(x>=mWidth || y>=mHeight)
    {
        throw std::out_of_range("");
    }
}

const std::optional<std::string>& Grid<const char*>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

std::optional<std::string>& Grid<const char*>::at(size_t x, size_t y)
{
    return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x,y));
}