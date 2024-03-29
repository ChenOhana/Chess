#pragma once

#include <vector>
#include "Check.h"

#define KB 1024
#define BOARD 64
#define OUT_OF_BOUNDRIES -1

enum positions
{
	A8 = 0, B8, C8, D8, E8, F8, G8, H8, A7, B7, C7, D7, E7, F7, G7, H7, A6, B6, C6, D6, E6, F6, G6, H6, A5, B5, C5, D5, E5, F5, G5, H5, A4, B4, C4, D4, E4, F4, G4, H4, A3, B3, C3, D3, E3, F3, G3, H3, A2, B2, C2, D2, E2, F2, G2, H2, A1, B1, C1, D1, E1, F1, G1, H1
};

enum states
{
	ZERO = '0', ONE = '1', TWO = '2', THREE = '3', SIX = '6', EIGHT = '8'
};

//Static class

class Utilities
{
public:
	static int getPlace(std::string place); //return index (int) in board by position (string)
	static std::string getPosition(int place); //return position (string) by index (int) in board
	static bool check(char* board); //check if there is check
	static bool checkmate(char* board); //check if there is checkmate
};