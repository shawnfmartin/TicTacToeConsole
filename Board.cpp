#include "Board.h"
#include <iostream>

using namespace std;

const int boardSize = 3;

Board::Board()
{
	matrix = setMatrix();
	turn = 'O';
}


Board::~Board()
{
}


void Board::setBoard()
{
	cout << "  | 1 | 2 | 3 |";
	cout << "---------------";
	cout << "1 | . | . | . |";
	cout << "---------------";
	cout << "2 | . | . | . |";
	cout << "---------------";
	cout << "3 | . | . | . |";
	cout << "---------------";
}

void Board::displayBoard()
{
	char t = 'X';
	cout << "  | 1 | 2 | 3 |" << endl;
	cout << "---------------" << endl;
	cout << "1 | " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << " |" << endl;
	cout << "---------------" << endl;
	cout << "2 | " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << " |" << endl;
	cout << "---------------" << endl;
	cout << "3 | " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << " |" << endl;
	cout << "---------------" << endl;
}

void Board::takeTurn(char turn)
{
	char otherTurn;
	if (turn == 'O')
		otherTurn = 'X';
	else
		otherTurn = 'O';

	int xValue;
	int yValue;
	cout << "Enter what X value you want to go (1-" << boardSize <<"): ";
	cin >> xValue;
	cout << endl;
	cout << "Enter what Y value you want to go (1-" << boardSize << "): ";
	cin >> yValue;
	cout << endl;
	if (matrix[yValue - 1][xValue - 1] == otherTurn)
	{
		cout << "******That spot is taken, go again!******" << endl;
		takeTurn(turn);
	}
	else {
		matrix[yValue - 1][xValue - 1] = turn;
	}

}

char** Board::setMatrix()
{
	matrix = new char*[boardSize];
	for (int i = 0; i < boardSize; i++)
	{
		matrix[i] = new char[boardSize];
	}

	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)			
			matrix[i][j] = 0;

	return matrix;
}

bool Board::gameOver()
{
	char otherTurn;
	if (turn == 'O')
		otherTurn = 'X';
	else
		otherTurn = 'O';
	char s1, s2, s3, s4, s5, s6, s7, s8, s9;
	s1 = matrix[0][0];
	s2 = matrix[0][1];
	s3 = matrix[0][2];

	s4 = matrix[1][0];
	s5 = matrix[1][1];
	s6 = matrix[1][2];

	s7 = matrix[2][0];
	s8 = matrix[2][1];
	s9 = matrix[2][2];

	bool topRowWint = (s1 == s2 && s2 == s3 && s1 == turn);
	bool middleRowWint = (s4 == s5 && s5 == s6 && s4 == turn);
	bool bottomRowWint = (s7 == s8 && s8 == s9 && s7 == turn);

	bool leftColumnWint = (s1 == s4 && s4 == s7 && s1 == turn);
	bool middleColumnWint = (s2 == s5 && s5 == s8 && s2 == turn);
	bool rightColumnWint = (s3 == s6 && s6 == s9 && s3 == turn);

	bool posDiagWint = (s7 == s5 && s5 == s3 && s7 == turn);
	bool negDiagWint = (s1 == s5 && s5 == s9 && s1 == turn);



	bool topRowWino = (s1 == s2 && s2 == s3 && s1 == otherTurn);
	bool middleRowWino = (s4 == s5 && s5 == s6 && s4 == otherTurn);
	bool bottomRowWino = (s7 == s8 && s8 == s9 && s7 == otherTurn);

	bool leftColumnWino = (s1 == s4 && s4 == s7 && s1 == otherTurn);
	bool middleColumnWino = (s2 == s5 && s5 == s8 && s2 == otherTurn);
	bool rightColumnWino = (s3 == s6 && s6 == s9 && s3 == otherTurn);

	bool posDiagWino = (s7 == s5 && s5 == s3 && s7 == otherTurn);
	bool negDiagWino = (s1 == s5 && s5 == s9 && s1 == otherTurn);

	if (topRowWint == true || middleRowWint == true || bottomRowWint == true
		|| leftColumnWint == true || middleColumnWint == true || rightColumnWint == true
		|| posDiagWint == true || negDiagWint == true)
	{
		displayBoard();
		cout << turn << " wins!" << endl;;
		return true;
	}
	else if (topRowWino == true || middleRowWino == true || bottomRowWino == true
		|| leftColumnWino == true || middleColumnWino == true || rightColumnWino == true
		|| posDiagWino == true || negDiagWino == true)
	{
		displayBoard();
		cout << otherTurn << " wins!" << endl;
		return true;
	}
	return false;
}