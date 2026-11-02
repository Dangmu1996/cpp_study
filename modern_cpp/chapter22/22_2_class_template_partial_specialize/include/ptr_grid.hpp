#pragma once
// 모든 종류의 포인터 타입에 대해 Grid 클래스 템플릿을 특수화함.
#include "orig_grid.hpp"
#include <memory>
#include <vector>

template <typename T>
class Grid<T*>
{
public:
    explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    virtual ~Grid() = default;

    // 복제 생성자와 복제 대입 연산자
    Grid(const Grid& src);
    Grid<T*>& operator=(const Grid& rhs);

    // 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
    Grid(Grid&& src) = default;
    Grid<T*>& operator=(Grid&& rhs) = default;
    void swap(Grid& other) noexcept;

    std::unique_ptr<T>& at(size_t x, size_t y);
    const std::unique_ptr<T>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }
    
    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::unique_ptr<T>>> mCells;
    size_t mWidth = 0, mHeight = 0;
};

template <typename T>
Grid<T*>::Grid(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for(auto& column : mCells)
    {
        column.resize(mHeight);
    }
}

template <typename T>
void Grid<T*>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T>
const std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T>
std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y)
{
	return const_cast<std::unique_ptr<T>&>(std::as_const(*this).at(x, y));
}

template <typename T>
void Grid<T*>::swap(Grid& other) noexcept
{
    using std::swap;
    swap(mWidth, other.mWidth);
    swap(mHeight, other.mHeight);
    swap(mCells, other.mCells);
}

template <typename T>
Grid<T*>::Grid(const Grid& src)
    :Grid(src.mWidth, src.mHeight)
{
    // 이 생성자의 생성자 이니셜라이저는 먼저 적절한 메모리 공산을 할당하는 작업을
    // 비복제 생성자에 위임한다.
    // 그리고 나서 데이터를 복제한다.
    for(size_t i = 0; i < mWidth; i++){
        for(size_t j = 0; j<mHeight; j++){
            // 복제 생성자로 원소에 대해 깊은 복제를 수행한다.
            if(src.mCells[i][j]){
                mCells[i][j].reset(new T(*(src.mCells[i][j])));
            }
        }
    }
}

template <typename T>
Grid<T*>& Grid<T*>::operator=(const Grid& rhs)
{
    // check for self-assignment.
    if(this==&rhs){
        return *this;
    }

    auto copy = rhs;
    swap(copy);
    return *this;
}