#include "Grid.hpp"
#include <memory>
#include <vector>
#include <utility>
#include <optional>


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

/*이렇게 하면 int, double vector<int> 에만 인스턴스화 된다고 한다.
그리고 이렇게 했을 때만 따로 빌드를 해줘야 한다고 함. 이게 왜나면 이 아이들은 그냥 빌드 과정에서 만들어 주는 것이라서

이거 않쓰려면 빌드하지 말고 그냥 써야함
*/
template class Grid<int>;
template class Grid<double>;
template class Grid<std::vector<int>>;
