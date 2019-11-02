#include "Utilities.h"

/*
Function will get position (string) and return its index in the board.
Input: place
Output: index - int
*/

int Utilities::getPlace(std::string place)
{
	if (place == "a8") return A8;
	if (place == "b8") return B8;
	if (place == "c8") return C8;
	if (place == "d8") return D8;
	if (place == "e8") return E8;
	if (place == "f8") return F8;
	if (place == "g8") return G8;
	if (place == "h8") return H8;
	if (place == "a7") return A7;
	if (place == "b7") return B7;
	if (place == "c7") return C7;
	if (place == "d7") return D7;
	if (place == "e7") return E7;
	if (place == "f7") return F7;
	if (place == "g7") return G7;
	if (place == "h7") return H7;
	if (place == "a6") return A6;
	if (place == "b6") return B6;
	if (place == "c6") return C6;
	if (place == "d6") return D6;
	if (place == "e6") return E6;
	if (place == "f6") return F6;
	if (place == "g6") return G6;
	if (place == "h6") return H6;
	if (place == "a5") return A5;
	if (place == "b5") return B5;
	if (place == "c5") return C5;
	if (place == "d5") return D5;
	if (place == "e5") return E5;
	if (place == "f5") return F5;
	if (place == "g5") return G5;
	if (place == "h5") return H5;
	if (place == "a4") return A4;
	if (place == "b4") return B4;
	if (place == "c4") return C4;
	if (place == "d4") return D4;
	if (place == "e4") return E4;
	if (place == "f4") return F4;
	if (place == "g4") return G4;
	if (place == "h4") return H4;
	if (place == "a3") return A3;
	if (place == "b3") return B3;
	if (place == "c3") return C3;
	if (place == "d3") return D3;
	if (place == "e3") return E3;
	if (place == "f3") return F3;
	if (place == "g3") return G3;
	if (place == "h3") return H3;
	if (place == "a2") return A2;
	if (place == "b2") return B2;
	if (place == "c2") return C2;
	if (place == "d2") return D2;
	if (place == "e2") return E2;
	if (place == "f2") return F2;
	if (place == "g2") return G2;
	if (place == "h2") return H2;
	if (place == "a1") return A1;
	if (place == "b1") return B1;
	if (place == "c1") return C1;
	if (place == "d1") return D1;
	if (place == "e1") return E1;
	if (place == "f1") return F1;
	if (place == "g1") return G1;
	if (place == "h1") return H1;
	return OUT_OF_BOUNDRIES;
}

/*
Function will get index (int) and return its position (string) in the board.
Input: place
Output: position - string
*/

std::string Utilities::getPosition(int place)
{
	if (place == A8) return "a8";
	if (place == B8) return "b8";
	if (place == C8) return "c8";
	if (place == D8) return "d8";
	if (place == E8) return "e8";
	if (place == F8) return "f8";
	if (place == G8) return "g8";
	if (place == H8) return "h8";
	if (place == A7) return "a7";
	if (place == B7) return "b7";
	if (place == C7) return "c7";
	if (place == D7) return "d7";
	if (place == E7) return "e7";
	if (place == F7) return "f7";
	if (place == G7) return "g7";
	if (place == H7) return "h7";
	if (place == A6) return "a6";
	if (place == B6) return "b6";
	if (place == C6) return "c6";
	if (place == D6) return "d6";
	if (place == E6) return "e6";
	if (place == F6) return "f6";
	if (place == G6) return "g6";
	if (place == H6) return "h6";
	if (place == A5) return "a5";
	if (place == B5) return "b5";
	if (place == C5) return "c5";
	if (place == D5) return "d5";
	if (place == E5) return "e5";
	if (place == F5) return "f5";
	if (place == G5) return "g5";
	if (place == H5) return "h5";
	if (place == A4) return "a4";
	if (place == B4) return "b4";
	if (place == C4) return "c4";
	if (place == D4) return "d4";
	if (place == E4) return "e4";
	if (place == F4) return "f4";
	if (place == G4) return "g4";
	if (place == H4) return "h4";
	if (place == A3) return "a3";
	if (place == B3) return "b3";
	if (place == C3) return "c3";
	if (place == D3) return "d3";
	if (place == E3) return "e3";
	if (place == F3) return "f3";
	if (place == G3) return "g3";
	if (place == H3) return "h3";
	if (place == A2) return "a2";
	if (place == B2) return "b2";
	if (place == C2) return "c2";
	if (place == D2) return "d2";
	if (place == E2) return "e2";
	if (place == F2) return "f2";
	if (place == G2) return "g2";
	if (place == H2) return "h2";
	if (place == A1) return "a1";
	if (place == B1) return "b1";
	if (place == C1) return "c1";
	if (place == D1) return "d1";
	if (place == E1) return "e1";
	if (place == F1) return "f1";
	if (place == G1) return "g1";
	if (place == H1) return "h1";
}


/*
Function will check if there is check and return result.
Input: pointer to board
Output: true or false
*/

bool Utilities::check(char* board)
{
	std::string whiteKing = "", blackKing = "";

	for (int i = 0; i < BOARD; i++)
	{
		if (board[i] == 'k')
		{
			blackKing = getPosition(i);
		}
		if (board[i] == 'K')
		{
			whiteKing = getPosition(i);
		}
	}

	Check black(blackKing, "a1", false, board);
	Check white(whiteKing, "a1", true, board);
	char currPlace = 'a';
	int index = 0;

	for (int i = 0; i < black.moves.size(); i++)
	{
		index = Utilities::getPlace(black.moves[i]);

		if (index != OUT_OF_BOUNDRIES)
		{
			currPlace = board[index];
		
			if (currPlace > 'A' && currPlace < 'Z')
			{
				return true;
			}
		}
	}

	for (int i = 0; i < white.moves.size(); i++)
	{
		index = Utilities::getPlace(white.moves[i]);

		if (index != OUT_OF_BOUNDRIES)
		{
			currPlace = board[index];

			if (currPlace > 'a' && currPlace < 'z')
			{
				return true;
			}
		}
	}
	return false;
}

/*
Function will check if there is checkmate and return result.
Input: pointer to board
Output: true or false
*/

bool Utilities::checkmate(char* board)
{
	std::string whiteKing = "", blackKing = "";

	for (int i = 0; i < BOARD; i++)
	{
		if (board[i] == 'k')
		{
			blackKing = getPosition(i);
		}
		if (board[i] == 'K')
		{
			whiteKing = getPosition(i);
		}
	}

	if (whiteKing == "" || blackKing == "")
	{
		return true;
	}
	return false;
}