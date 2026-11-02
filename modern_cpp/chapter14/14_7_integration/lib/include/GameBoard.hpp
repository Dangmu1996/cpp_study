#pragma once

#include <stdexcept>
#include <utility>
#include <exception>

class GamePiece{};

class GameBoard
{
    public:
        //제네릭 GameBoard. 상용자 크기를 지정한다.
        explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
        GameBoard(const GameBoard& src); //복사 생성자
        virtual ~GameBoard() noexcept;
        GameBoard& operator=(const GameBoard& rhs); //대입 연산자

        GamePiece& at(size_t x, size_t y);
        const GamePiece& at(size_t x, size_t y) const;

        size_t getHeight() const noexcept { return mHeight; }
        size_t getWidth() const noexcept { return mWidth; }

        static const size_t kDefaultWidth = 100;
        static const size_t kDefaultHeight = 100;

        friend void swap(GameBoard& first, GameBoard& second) noexcept;
    private:
        void cleanup() noexcept;
        void verifyCoordinate(size_t x, size_t y) const;

        //게임 말을 동적으로 저장하는 객체
        GamePiece** mCells = nullptr;
        size_t mWidth =0, mHeight =0;
};