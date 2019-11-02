#include "Rook.h"

/*
Constructor with initialization line, generates moves for rook.
Input: src, dst, color, board
*/

Rook::Rook(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generatePlusMoves(board);
}

//Destructor

Rook::~Rook()
{

}