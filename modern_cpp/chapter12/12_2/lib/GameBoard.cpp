#include "GameBoard.hpp"

GameBoard::GameBoard(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells.resize(mWidth);
    for(auto & column : mCells)
    {
        column.resize(mHeight);
    }
}

GameBoard::GameBoard(const GameBoard & src)
    : GameBoard(src.mWidth, src.mHeight)
{
    //여기 나온 생성자 이니셜라이저는 먼저 적절한 크기의 메모리를 할당하는 작업을 비복제 생성자에게 위임

    //그리고 나서 데이터를 복제함
    for(size_t i =0; i< mWidth; i++)
    {
        for(size_t j=0; j<mHeight; j++)
        {
            if(src.mCells[i][j])
                mCells[i][j]=src.mCells[i][j]->clone();
        }
    }
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if(x>mWidth || y>mHeight)
    {
        throw std::out_of_range("");
    }
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard &rhs)
{
    //자기 자신을 대입하는지 검사
    if(this == &rhs)
    {
        return *this;
    }
    //복제 후 맞바꾸기 -> 이게 포인트라함
    GameBoard temp(rhs);
    swap(*this, temp);
    return *this;
}

const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
    return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}
//utility에 정의된 std::as_const()로 *this를 cosnt GameBoard&로 캐스팅하고, const 버전의 at을 호출한 다음에 const_cast()를 적용하여 리턴 값에서는 const를 제거하는 방식