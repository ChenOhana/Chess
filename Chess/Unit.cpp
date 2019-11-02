#include "Unit.h"
#include "Utilities.h"

/*
Constructor will initialize class fields.
Input: src, dst, color, board
*/

Unit::Unit(std::string src, std::string dst, bool color, char board[])
{
	this->src = src;
	this->dst = dst;
	this->color = color;
}

//Destructor

Unit::~Unit()
{
	
}

/*
Function will try to move piece and return result/state.
Input: pointer to board
Output: result
*/

char Unit::move(char* board)
{
	char position = board[Utilities::getPlace(this->src)];
	char dest = board[Utilities::getPlace(this->dst)];

	if (this->color)
	{
		if (dest > 'A' && dest < 'Z')
		{
			return THREE;
		}
	}
	else
	{
		if (dest > 'a' && dest < 'z')
		{
			return THREE;
		}
	}

	for (int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == this->dst)
		{
			board[Utilities::getPlace(dst)] = position;
			board[Utilities::getPlace(src)] = '#';

			if (Utilities::checkmate(board))
			{
				return EIGHT;
			}
			else if (Utilities::check(board))
			{
				return ONE;
			}
			else
			{
				return ZERO;
			}
		}
	}
	return SIX;
}

/*
Function will push move to vector of moves and return if succeeded.
Input: src, letterOffset, numberOffset
Output: result
*/

int Unit::generateMove(std::string src, int letterOffset, int numberOffset, char board[])
{
	stringstream ss;
	std::string positionStr;
	std::string positionStr2;

	char positionChr = char(int(src[0]) + letterOffset);
	char positionChr2 = char(int(src[1]) + numberOffset);

	ss << positionChr;
	ss >> positionStr;
	ss.clear();
	ss << positionChr2;
	ss >> positionStr2;
	ss.clear();

	positionStr = positionStr + positionStr2;

	if (Utilities::getPlace(positionStr) != OUT_OF_BOUNDRIES)
	{
		this->moves.push_back(positionStr);

		if (board[Utilities::getPlace(positionStr)] != '#')
		{
			return 0;
		}
		return 1;
	}
	return OUT_OF_BOUNDRIES;
}

/*
Function will push plus shaped moves to vector of moves.
Input: board
Output: None
*/

void Unit::generatePlusMoves(char board[])
{
	int i = 0, state = 0;

	i = 1;
	do
	{
		state = generateMove(src, 0, i, board); //check up direction
		i++;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = -1;
	do
	{
		state = generateMove(src, 0, i, board); //check down direction
		i--;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = 1;
	do
	{
		state = generateMove(src, i, 0, board); //check right direction
		i++;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = -1;
	do
	{
		state = generateMove(src, i, 0, board); //check left direction
		i--;
	} while (state && state != OUT_OF_BOUNDRIES);
}

/*
Function will push X shaped moves to vector of moves.
Input: board
Output: None
*/

void Unit::generateXMoves(char board[])
{
	int i = 0, j = 0, state = 0;

	i = 1;
	j = 1;
	do
	{
		state = generateMove(src, i, j, board); //check upRight diagonal line
		i++;
		j++;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = 1;
	j = -1;
	do
	{
		state = generateMove(src, i, j, board); //check downRight diagonal line
		i++;
		j--;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = -1;
	j = 1;
	do
	{
		state = generateMove(src, i, j, board); //check upLeft diagonal line
		i--;
		j++;
	} while (state && state != OUT_OF_BOUNDRIES);
	i = -1;
	j = -1;
	do
	{
		state = generateMove(src, i, j, board); //check downLeft diagonal line
		i--;
		j--;
	} while (state && state != OUT_OF_BOUNDRIES);
}