#pragma once

#include <optional>
#include <vector>
#include <memory>
#include <utility>


//이렇게 하면 컴파일 전에 크기를 알 수 있어서 좋다고 함. // 매게변수도 디폴트 값이 가능하다
template <typename T=int, size_t WIDTH=10, size_t HEIGHT=10>
class Grid
{
    public:
        Grid() = default;
        virtual ~Grid() = default;

        Grid(const Grid& src) = default;
        Grid<T, WIDTH, HEIGHT> & operator = (const Grid& rhs) = default;

        std::optional<T>& at(size_t x, size_t y);
        const std::optional<T>& at(size_t x, size_t y) const;

        size_t getHeight() const {return HEIGHT;}
        size_t getWidth() const {return WIDTH; }

        template<typename E, size_t WIDTH2, size_t HEIGHT2>
        Grid(const Grid<E, WIDTH2, HEIGHT2>& src);

        template<typename E, size_t WIDTH2, size_t HEIGHT2>
        Grid<T, WIDTH, HEIGHT> &operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs);

        void swap(Grid& other) noexcept;
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::optional<T> mCells[WIDTH][HEIGHT];

};

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
    if(x>=WIDTH || y>=HEIGHT)
    {
        throw std::out_of_range("");
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x,y));
}


template <typename T, size_t WIDTH, size_t HEIGHT>
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2> &src)
{
    for(size_t i=0; i<WIDTH; i++)
    {
        for(size_t j=0; j<HEIGHT; j++)
        {
            if(i<WIDTH2 && j <HEIGHT2)
            {
                mCells[i][j] = src.at(i, j);
            }
            else
            {
                mCells[i][j].reset();
            }
        }
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T,WIDTH,HEIGHT>::operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
    //자기 자신을 대입할 경우에 대한 예외처리를 할 필요가 없다.
    //이 버전의 대입 연산자는 T와 E가 서로 같으면 호출되지 않기 때문이다.

    //복제 후 맞바꾸기 위한 구문
    Grid<T, WIDTH, HEIGHT> temp(rhs); //모든 작업을 임시 인스턴스에서 처리한다/
    swap(temp); //익셉션이 발생하지 않는 연산으로만 처리한다.
    return *this;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid<T, WIDTH, HEIGHT>& other) noexcept
{
    using std::swap;

    swap(mCells, other.mCells);
}