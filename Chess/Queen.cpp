#include "Queen.h"

/*
Constructor with initialization line, generates moves for queen.
Input: src, dst, color, board
*/

Queen::Queen(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generatePlusMoves(board);
	generateXMoves(board);
}

//Destructor

Queen::~Queen()
{

}