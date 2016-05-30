#pragma once
class Board
{
public:
	Board();
	~Board();

	void displayBoard();
	void setBoard();
	void takeTurn(char turn);
	char** setMatrix();
	char **matrix;
	char turn;
	bool gameOver();
};
