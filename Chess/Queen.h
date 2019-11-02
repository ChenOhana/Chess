#pragma once

#include "Unit.h"

class Queen : public Unit
{
public:
	Queen(std::string src, std::string dst, bool color, char board[]); //constructor
	~Queen(); //destructor
};