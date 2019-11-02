#include "King.h"

/*
Constructor with initialization line, generates moves for king.
Input: src, dst, color, board
*/

King::King(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generateMove(src, -1, 1, board);  //get up left position
	generateMove(src, 0, 1, board);   //get up position
	generateMove(src, 1, 1, board);   //get up right position
	generateMove(src, 1, 0, board);   //get right position
	generateMove(src, 1, -1, board);  //get down right position
	generateMove(src, 0, -1, board);  //get down position
	generateMove(src, -1, -1, board); //get down left position
	generateMove(src, -1, 0, board);  //get left position
}

//Destructor

King::~King()
{

}