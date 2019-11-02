#pragma once

#include "Unit.h"

class Bishop : public Unit
{
public:
	Bishop(std::string src, std::string dst, bool color, char board[]); //constructor
	~Bishop(); //destructor
};