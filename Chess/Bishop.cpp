#include "Bishop.h"

/*
Constructor with initialization line, generates moves for bishop.
Input: src, dst, color, board
*/

Bishop::Bishop(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generateXMoves(board);
}

//Destructor

Bishop::~Bishop()
{

}