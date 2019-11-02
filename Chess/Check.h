#pragma once

#include <algorithm>
#include "Unit.h"

#define DIFFERENCE 32
#define PAWN 1
#define PAWN_2 3
#define PAWN_3 5
#define PAWN_4 7

class Check : public Unit
{
public:
	Check(std::string src, std::string dst, bool color, char board[]); //constructor
	~Check(); //destructor
};