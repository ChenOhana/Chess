#pragma once

#include "Unit.h"

class Rook : public Unit
{
public:
	Rook(std::string src, std::string dst, bool color, char board[]); //constructor
	~Rook(); //destructor
};