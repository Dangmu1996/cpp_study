#pragma once
#include "Grid.hpp"
#include <string>

// 모든 매개변수에 대해서 일부에 대해서만 특수화를 한다.

template<size_t WIDTH, size_t HEIGHT>
class Grid<const char*, WIDTH, HEIGHT>
{
public:
    Grid() = default;
    virtual ~Grid() = default;

    //복제 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
    Grid(const Grid& src) = default;
    Grid& operator=(const Grid& rhs) = default;

    std::optional<std::string>& at(size_t x, size_t y);
    const std::optional<std::string>& at(size_t x, size_t y) const;

    size_t getHeight() const { return HEIGHT; }
    size_t getWidth() const {return WIDTH; }

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::optional<std::string> mCells[WIDTH][HEIGHT];
};

template<size_t WIDTH, size_t HEIGHT>
void Grid<const char*, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
    if(x >= WIDTH || y>= HEIGHT){
        throw std::out_of_range("");
    }
}

template<size_t WIDTH, size_t HEIGHT>
const std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template<size_t WIDTH, size_t HEIGHT>
std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return const_cast<std::optional<std::string>&>(as_cast(*this).at(x, y));
}