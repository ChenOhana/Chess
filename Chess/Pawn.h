#pragma once

#include "Unit.h"

class Pawn : public Unit
{
public:
	Pawn(std::string src, std::string dst, bool color, char board[]); //constructor
	~Pawn(); //destructor
};