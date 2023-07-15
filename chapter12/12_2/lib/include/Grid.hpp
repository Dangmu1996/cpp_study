#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <optional>
#include <stdexcept>


template <typename T>
class Grid
{
public:
    explicit Grid(size_t width = kDefaultWidth, size_t height=kDefaultHeight);
    virtual ~Grid() = default;

    Grid(const Grid & src) = default;
    Grid<T>& operator=(const Grid& rhs) = default;

    Grid(Grid&& src) = default;
    Grid<T>& operator=(Grid && rhs) = default;

    //optional을 쓰면 빈 값에 대해서 표현 할 수 있음
    std::optional<T>& at(size_t x, size_t y);
    const std::optional<T>& at(size_t x, size_t y) const;

    size_t getHeight() const{return mHeight;}
    size_t getWidth() const{return mWidth;}

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T>>> mCells;
    size_t mWidth, mHeight;

};

//#include "./GridDefinition.hpp"

/*Compiling 할때는 이렇게 사용해야함.
이게 선언 부분과 정의 부분을 한꺼번에 봐야 해서 그렇다고 함.
템플릿은 빌드하는데 조금 이상하긴 함
*/
