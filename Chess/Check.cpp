#include "Check.h"
#include "Utilities.h"

/*
Constructor with initialization line, generates all moves that create check for a given src.
Input: src, dst, color, board
*/

Check::Check(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	generateMove(src, -1, 2, board);
	generateMove(src, 1, 2, board);
	generateMove(src, 2, 1, board);
	generateMove(src, 2, -1, board);
	generateMove(src, 1, -2, board);
	generateMove(src, -1, -2, board);
	generateMove(src, -2, -1, board);
	generateMove(src, -2, 1, board);

	char position = 'a';
	int difference = 0;

	if (color)
	{
		difference = DIFFERENCE;  // 'X' + DIFFERENCE = 'x'
	}

	for (int i = 0; i < this->moves.size(); i++)
	{
		position = board[Utilities::getPlace(this->moves[i])];
		if (position != 'N' + difference)
		{
			this->moves.erase(this->moves.begin() + i);
			i--;
		}
	}
	int start = this->moves.size();

	generatePlusMoves(board);

	for (int i = start; i < this->moves.size(); i++)
	{
		position = board[Utilities::getPlace(this->moves[i])];
		
		if (position != 'R' + difference && position != 'Q' + difference)
		{
			this->moves.erase(std::remove(this->moves.begin(), this->moves.end(), this->moves[i]), this->moves.end());
			i--;
		}
	}
	start = this->moves.size();

	generateXMoves(board);

	for (int i = start; i < this->moves.size(); i++)
	{
		position = board[Utilities::getPlace(this->moves[i])];

		if (position != 'B' + difference && position != 'Q' + difference)
		{
			this->moves.erase(std::remove(this->moves.begin(), this->moves.end(), this->moves[i]), this->moves.end());
			i--;
		}
	}
	start = this->moves.size();

	if (generateMove(src, -1, 1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }   //get up left position
	if (generateMove(src, 0, 1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }    //get up position
	if (generateMove(src, 1, 1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }    //get up right position
	if (generateMove(src, 1, 0, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }    //get right position
	if (generateMove(src, 1, -1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }   //get down right position
	if (generateMove(src, 0, -1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }   //get down position
	if (generateMove(src, -1, -1, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }  //get down left position
	if (generateMove(src, -1, 0, board) == OUT_OF_BOUNDRIES) { this->moves.push_back("#"); }   //get left position

	int arr[SIZE] = { 0 }, j = 0;

	for (int i = start; i < this->moves.size(); i++)
	{
		position = board[Utilities::getPlace(this->moves[i])];
		
		if (i == start + PAWN || i == start + PAWN_2 || i == start + PAWN_3 || i == start + PAWN_4)
		{
			if (position != 'R' + difference && position != 'Q' + difference && position != 'K' + difference)
			{
				arr[j] = i;
				j++;
			}
		}
		else
		{
			if (position != 'P' + difference && position != 'B' + difference && position != 'Q' + difference && position != 'K' + difference)
			{
				arr[j] = i;
				j++;
			}
			if (color)
			{
				if (i >= 0 && (i == start - 1 + PAWN_3 || i == start -1 + PAWN_4) && board[Utilities::getPlace(this->moves[i])] == 'P' + difference)
				{
					arr[j] = i;
					j++;
				}
			}
			else
			{
				if (i >= 0 && (i == start - 1 + PAWN || i == start - 1 + PAWN_2) && board[Utilities::getPlace(this->moves[i])] == 'P' + difference)
				{
					arr[j] = i;
					j++;
				}
			}
		}
	}

	for (int i = j - 1; i >= 0; i--)
	{
		this->moves[arr[i]] = this->moves.back();
		this->moves.pop_back();
	}
}

//Destructor

Check::~Check()
{

}