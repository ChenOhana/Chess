#include "Knight.h"

/*
Constructor with initialization line, generates moves for knight.
Input: src, dst, color, board
*/

Knight::Knight(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generateMove(src, -1, 2, board);
	generateMove(src, 1, 2, board);
	generateMove(src, 2, 1, board);
	generateMove(src, 2, -1, board);
	generateMove(src, 1, -2, board);
	generateMove(src, -1, -2, board);
	generateMove(src, -2, -1, board);
	generateMove(src, -2, 1, board);
}

//Destructor

Knight::~Knight()
{

}