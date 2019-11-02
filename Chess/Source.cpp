#include <iostream>
#include <thread>
#include "Utilities.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

#define BOARD 1024

using namespace std;

void main()
{
	srand(time_t(NULL));
	
	Pipe pipe;
	bool isConnect = pipe.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = pipe.connect();
		}
		else 
		{
			pipe.close();
			return;
		}
	}

	char msgToGraphics[66];
	// msgToGraphics should contain the board string accord the protocol
	char board[65] = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR";

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	
	pipe.sendMessageToGraphics(msgToGraphics); // send the board string
	
	std::string msgFromGraphics;
	char state[2] = "";
	char position = 'a';
	std::string src = "";
	std::string dst = "";
	Bishop b("a1", "a1", false, board);
	King k("a1", "a1", false, board);
	Knight n("a1", "a1", false, board);
	Pawn p("a1", "a1", false, board);
	Queen q("a1", "a1", false, board);
	Rook r("a1", "a1", false, board);

	bool turn = false;

	while (msgFromGraphics != "quit")
	{
		msgFromGraphics = pipe.getMessageFromGraphics();
		src = msgFromGraphics.substr(0, 2);
		dst = msgFromGraphics.substr(2, 2);
		position = board[Utilities::getPlace(src)];

		if (turn && position > 'a' && position < 'z') { state[0] = TWO; }		     //trying to move the
		else if (!turn && position > 'A' && position < 'Z') { state[0] = TWO; }		//enemy's chess piece
		else
		{
			switch (position)
			{
			case 'b':
			case 'B':
				b = Bishop(src, dst, turn, board);
				state[0] = b.move(board);
				break;
			case 'k':
			case 'K':
				k = King(src, dst, turn, board);
				state[0] = k.move(board);
				break;
			case 'n':
			case 'N':
				n = Knight(src, dst, turn, board);
				state[0] = n.move(board);
				break;
			case 'p':
			case 'P':
				p = Pawn(src, dst, turn, board);
				state[0] = p.move(board);
				break;
			case 'q':
			case 'Q':
				q = Queen(src, dst, turn, board);
				state[0] = q.move(board);
				break;
			case 'r':
			case 'R':
				r = Rook(src, dst, turn, board);
				state[0] = r.move(board);
				break;
			default:
				state[0] = TWO;
				break;
			}
		}

		if (state[0] == ZERO || state[0] == ONE) { turn = !turn; }  //if valid move
		pipe.sendMessageToGraphics(state);
	}

	pipe.close();
}