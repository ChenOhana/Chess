#include "Pawn.h"
#include "Utilities.h"

/*
Constructor with initialization line, generates moves for pawn.
Input: src, dst, color, board
*/

Pawn::Pawn(std::string src, std::string dst, bool color, char board[]) : Unit(src, dst, color, board)
{
	stringstream ss;

	bool firstTime = false;
	bool insert = true;
	int position = Utilities::getPlace(src);
	char dest = board[Utilities::getPlace(dst)];

	if (color)
	{
		int white[SIZE] = { A2, B2, C2, D2, E2, F2, G2, H2 }, i = 0;

		if (dest > 'a' && dest < 'z')
		{
			insert = false;
		}

		for (i = 0; i < SIZE; i++)
		{
			if (position == white[i])
			{
				firstTime = true;
				break;
			}
		}
	}
	else
	{
		int black[SIZE] = { A7, B7, C7, D7, E7, F7, G7, H7 }, i = 0;

		if (dest > 'A' && dest < 'Z')
		{
			insert = false;
		}

		for (i = 0; i < SIZE; i++)
		{
			if (position == black[i])
			{
				firstTime = true;
				break;
			}
		}
	}
	
	if (insert)
	{
		std::string bStr;
		std::string wStr;
		char bChr = char(int(src[1]) - 1);
		char wChr = char(int(src[1]) + 1);
		ss << bChr;
		ss >> bStr;
		ss.str("");
		ss.clear();
		ss << wChr;
		ss >> wStr;
		ss.str("");
		ss.clear();

		std::string bPosition = src[0] + bStr;
		std::string wPosition = src[0] + wStr;
		std::string bPosition2 = "";
		std::string wPosition2 = "";

		if (firstTime)
		{
			bChr = char(int(src[1]) - 2);
			wChr = char(int(src[1]) + 2);
			ss << bChr;
			ss >> bStr;
			ss.str("");
			ss.clear();
			ss << wChr;
			ss >> wStr;
			ss.str("");
			ss.clear();

			bPosition2 = src[0] + bStr;
			wPosition2 = src[0] + wStr;
		}

		char bPos = board[Utilities::getPlace(bPosition)];
		char wPos = board[Utilities::getPlace(wPosition)];

		if (this->color)
		{
			if (!(wPos > 'a' && wPos < 'z' || wPos > 'A' && wPos < 'Z'))
			{
				this->moves.push_back(wPosition);
				this->moves.push_back(wPosition2);
			}
		}
		else
		{
			if (!(bPos > 'a' && bPos < 'z' || bPos > 'A' && bPos < 'Z'))
			{
				this->moves.push_back(bPosition);
				this->moves.push_back(bPosition2);
			}
		}
	}
	else
	{
		std::string bNumStr;
		std::string bChrStr;
		std::string bChr2Str;
		std::string wNumStr;
		std::string wChrStr;
		std::string wChr2Str;

		char bNum = char(int(src[1]) - 1);
		char bChr = char(int(src[0]) - 1);
		char bChr2 = char(int(src[0]) + 1);
		char wNum = char(int(src[1]) + 1);
		char wChr = char(int(src[0]) - 1);
		char wChr2 = char(int(src[0]) + 1);
		ss << bNum;
		ss >> bNumStr;
		ss.str("");
		ss.clear();
		ss << bChr;
		ss >> bChrStr;
		ss.str("");
		ss.clear();
		ss << bChr2;
		ss >> bChr2Str;
		ss.str("");
		ss.clear();

		ss << wNum;
		ss >> wNumStr;
		ss.str("");
		ss.clear();
		ss << wChr;
		ss >> wChrStr;
		ss.str("");
		ss.clear();
		ss << wChr2;
		ss >> wChr2Str;
		ss.str("");
		ss.clear();

		std::string bEatable = bChrStr + bNumStr;
		std::string bEatable2 = bChr2Str + bNumStr;
		std::string wEatable = wChrStr + wNumStr;
		std::string wEatable2 = wChr2Str + wNumStr;
		
		this->moves.push_back(this->color ? wEatable : bEatable);
		this->moves.push_back(this->color ? wEatable2 : bEatable2);
	}
}

//Destructor

Pawn::~Pawn()
{

}