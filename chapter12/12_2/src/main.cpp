//#include "GameBoardTemplate.hpp"
#include <memory>
#include <vector>
#include <utility>
#include <optional>

//#include "GamePiece.hpp"

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



int main(int argc, char **argv)
{
    Grid<int> myIntGrid;

    Grid<double> myDoubleGrid(11, 11);

    int x = myIntGrid.at(0,0).value_or(0);

    Grid<int> grid2(myIntGrid);
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;

    return 0;
}