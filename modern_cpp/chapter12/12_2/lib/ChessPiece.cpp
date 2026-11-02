#include "GamePiece.hpp"


std::unique_ptr<GamePiece> ChessPiece::clone() const
{
    //복제 생성자를 호출해서 이 인스턴스를 복제한다.
    return std::make_unique<ChessPiece>(*this);
}

std::unique_ptr<GamePiece> TicTacToePiece::clone() const
{
    return std::make_unique<TicTacToePiece>(*this);
}