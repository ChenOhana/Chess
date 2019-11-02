#pragma once

#include <vector>
#include <sstream>
#include "Pipe.h"

#define KB 1024
#define RANGE 8
#define SIZE 8

class Unit
{
protected:
	std::string src;
	std::string dst;
	bool color;
public:
	Unit(std::string src, std::string dst, bool color, char board[]); //constructor
	virtual ~Unit(); //destructor
	char move(char* board); //move piece
	int generateMove(std::string src, int letterOffset, int numberOffset, char board[]); //generates move
	void generatePlusMoves(char board[]); //generates plus shaped moves
	void generateXMoves(char board[]); //generates x shaped moves
	std::vector<std::string> moves; //vector of valid moves
};