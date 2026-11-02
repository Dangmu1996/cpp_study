#pragma once

#include <memory>

class GamePiece
{
    public:
        virtual std::unique_ptr<GamePiece> clone() const =0;  // 추상 베이스 클레스
};

//GamePiece가 추상 클래스니까 상속하면 clone 메서드를 구현해야 함
class ChessPiece : public GamePiece
{
    public:
        virtual std::unique_ptr<GamePiece> clone() const override;
};

class TicTacToePiece : public GamePiece
{
    public:
        virtual std::unique_ptr<GamePiece> clone() const override;
};