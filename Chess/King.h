#pragma once

#include "Unit.h"

class King : public Unit
{
public:
	King(std::string src, std::string dst, bool color, char board[]); //constructor 
	~King(); //destructor
};