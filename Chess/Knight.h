#pragma once

#include "Unit.h"

class Knight : public Unit
{
public:
	Knight(std::string src, std::string dst, bool color, char board[]); //constructor
	~Knight(); //destructor
};