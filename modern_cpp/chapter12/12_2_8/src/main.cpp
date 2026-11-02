#include "../lib/include/GameBoard.hpp"
#include <iostream>


int main(int argc, char** argv)
{
    GameBoard<const char*> chessboard(8, 8);
    chessboard.at(0,0) = "pawn";
    chessboard.move(0,0,0,1);
    return 0;
}