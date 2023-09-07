#include "GameBoard.hpp"

GameBoard::GameBoard(size_t width, size_t height)
{
    mCells = new GamePiece*[mWidth]{}; // 배열을 영으로 초기화한다.

    //mWidth와 mHeight멤버를 생성자 이니셜라이저로 초기화하면 안된다.
    //앞에 나온 mCells를 성공적으로 할당 했을 때만 초기화 해야 하기 때문이다.
    mWidth = width;
    mHeight = height;

    try
    {
        for(size_t i =0; i<width; ++i)
        {
            mCells[i] = new GamePiece[height];
        }
    }
    catch(...)
    {
        cleanup();
        //발생한 익셉션을 모두 bad_alloc익셉션 안에 중첩시킨다.
        std::throw_with_nested(std::bad_alloc());
    }
}

GameBoard::GameBoard(const GameBoard& src)
: GameBoard(src.mWidth, src.mHeight)
{
    //이 생성자에 대한 생성자 이니셜라이저는 
    //먼저 비복제 생성자에 메모리를 적절히 할당하는 작업을 위임한다.

    //그리고 나서 데이터를 복제한다.
    for(size_t i=0; i<mWidth; i++)
    {
        for(size_t j=0; j<mHeight; j++)
        {
            mCells[i][j]=src.mCells[i][j];
        }
    }
}

GameBoard::~GameBoard() noexcept
{
    cleanup();
}

void GameBoard::cleanup() noexcept
{
    for(size_t i=0; i<mWidth; i++)
    {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells=nullptr;
    mWidth = mHeight =0;
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if(x>=mWidth)
        throw std::out_of_range("x-coordinate beyond width");
    if(y>=mHeight)
        throw std::out_of_range("y-coordinate beyond hieght");
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    using std::swap;

    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    //자기 자신에 대입하는지 검사한다.
    if(this==&rhs)
        return *this;
    
    //복제 후 맞바꾸기
    GameBoard temp(rhs); //모든 작업을 임시 인스턴스에서 처리한다.
    swap(*this, temp);
    return *this;
}

const GamePiece& GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

GamePiece& GameBoard::at(size_t x, size_t y)
{
    return const_cast<GamePiece&>(std::as_const(*this).at(x, y));
}