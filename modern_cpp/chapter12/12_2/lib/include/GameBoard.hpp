#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <stdexcept>


#include "GamePiece.hpp"

class GameBoard
{
private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
    size_t mWidth, mHeight;

public:
    explicit GameBoard(size_t width=kDefaultWidth, size_t height=kDefaultHeight);
    GameBoard(const GameBoard & src); //복제 생성자

    virtual ~GameBoard()=default; //가상 디폴트 소멸자
    GameBoard & operator = (const GameBoard & rhs); // 대입 연산자

    //이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정
    GameBoard(GameBoard && src) = default;
    GameBoard & operator = (GameBoard && src) = default;

    //인수로 지정한 말을 복제하지 않고 레퍼런스로 리턴함 .GameBoard를 2차원 배열로 추상화하므로 인덱스로 지정한 객체의 복사본이 아닌 실제 객체를 제공하는 방식으로 배열에 접근하게 만듬
    //이렇게 구한 레퍼런스는 나중에 유요하지 않을 수 있기 때문에 리턴된 레퍼런스를 저장했다가 다시 쓸수 없고, 이 레퍼런스가 필요할 때마다 at을 호출해서 리턴된 레퍼런스를 곧바로 사용하게 하려고
    std::unique_ptr<GamePiece>& at(size_t x, size_t y);
    const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight;}
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    friend void swap(GameBoard& first, GameBoard& second) noexcept;
};
