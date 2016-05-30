#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
using namespace std;

int main()
{
	Board board;
	int turn = 0;
	while (board.gameOver() == false || turn == 9)
	{
		if (board.turn == 'O')
		{
			board.displayBoard();
			board.takeTurn(board.turn);
			board.turn = 'X';
		}
		else
		{
			board.displayBoard();
			board.takeTurn(board.turn);
			board.turn = 'O';
		}
		turn++;
		system("CLS");
	}

}