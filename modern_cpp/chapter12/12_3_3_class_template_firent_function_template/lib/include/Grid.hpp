#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <optional>

//이렇게 friend template쓰려면 Grid 템플렛에 대한 전방 선언
template<typename T> class Grid;

//템플릿화한 operator+에 대한 프로토타입
template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs);

// 템플릿을 T 타입으로 인스턴스화한 것에 대해 operator+를 T 타입으로 인스턴스화한 것이 friend가 돼야 한다.
// 따라서 클래스와 함스 인스턴스 사이의 friend 관계가 1:1 대응되게 해야 한다.
// 이때 operator+에 명시적으로 <T>를 지정한 부분이 중요하다 이렇게 하면 컴파일러는 operator+를 템플릿으로 취급한다.

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

    friend Grid<T> operator+ <T>(const Grid<T>& lhs, const Grid<T>& rhs);

    
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

template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs)
{
    size_t minWidth = std::min(lhs.getWidth(), rhs.getWidth());
    size_t minHeight = std::min(lhs.getHeight(), rhs.getHeight());

    Grid<T> result(minWidth, minHeight);
    for(size_t y=0; y<minHeight; ++y)
    {
        for(size_t x=0; x<minWidth; ++x)
        {
            const auto& leftElement = lhs.mCells[x][y];//private을 접근하니 문제가 생길 수도
            const auto& rightElement = rhs.mCells[x][y];
            if(leftElement.has_value() && rightElement.has_value())
            {
                result.at(x, y)=leftElement.value() + rightElement.value();
            }
        }
    }
    return result;

}