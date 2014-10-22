//
// Sudoku9by9Board.cpp
//

#include "Sudoku9by9Board.h"

Sudoku9by9Board::Sudoku9by9Board()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
		board[i][j] = 0;
		permanent[i][j] = false;
		}

	number_of_solutions_for_unit_test_check = NOSFUNTC_NOTSET;		/* Not set yet */
}

void Sudoku9by9Board::Print_Board()
{
	cout << endl << "--+------+-------+---------" << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << "  |";

		for (int j = 1; j <= 9; j++)
		{
			if (permanent[i][j] == true)
			{
				setcolor(12);
				cout << board[i][j] << " ";
				setcolor(7);
			}
			else cout << board[i][j] << " ";
			if (j % 3 == 0) cout << "| ";
		}
		cout << endl;
		if (i % 3 == 0) cout << "--+------+-------+---------" << endl;

	}
}

void Sudoku9by9Board::BuiltInUnitTest01Puzzle()
{
	board[1][1] = 5; permanent[1][1] = true;
	board[1][2] = 3; permanent[1][2] = true;
	board[1][5] = 7; permanent[1][5] = true;

	board[2][1] = 6; permanent[2][1] = true;
	board[2][4] = 1; permanent[2][4] = true;
	board[2][5] = 9; permanent[2][5] = true;
	board[2][6] = 5; permanent[2][6] = true;

	board[3][2] = 9; permanent[3][2] = true;
	board[3][3] = 8; permanent[3][3] = true;
	board[3][8] = 6; permanent[3][8] = true;

	board[4][1] = 8; permanent[4][1] = true;
	board[4][5] = 6; permanent[4][5] = true;
	board[4][9] = 3; permanent[4][9] = true;

	board[5][1] = 4; permanent[5][1] = true;
	board[5][4] = 8; permanent[5][4] = true;
	board[5][6] = 3; permanent[5][6] = true;
	board[5][9] = 1; permanent[5][9] = true;

	board[6][1] = 7; permanent[6][1] = true;
	board[6][5] = 2; permanent[6][5] = true;
	board[6][9] = 6; permanent[6][9] = true;

	board[7][2] = 6; permanent[7][2] = true;
	board[7][7] = 2; permanent[7][7] = true;
	board[7][8] = 8; permanent[7][8] = true;

	board[8][4] = 4; permanent[8][4] = true;
	board[8][5] = 1; permanent[8][5] = true;
	board[8][6] = 9; permanent[8][6] = true;
	board[8][9] = 5; permanent[8][9] = true;

	board[9][5] = 8; permanent[9][5] = true;
	board[9][8] = 7; permanent[9][8] = true;
	board[9][9] = 9; permanent[9][9] = true;
}

void Sudoku9by9Board::BuiltInUnitTest01Solution()
{
	number_of_solutions_for_unit_test_check = 1;		/* one unique solution */

	board[1][1] = 5; permanent[1][1] = true;
	board[1][2] = 3; permanent[1][2] = true;
	board[1][3] = 4; permanent[1][3] = false;
	board[1][4] = 6; permanent[1][4] = false;
	board[1][5] = 7; permanent[1][5] = true;
	board[1][6] = 8; permanent[1][6] = false;
	board[1][7] = 9; permanent[1][7] = false;
	board[1][8] = 1; permanent[1][8] = false;
	board[1][9] = 2; permanent[1][9] = false;

	board[2][1] = 6; permanent[2][1] = true;
	board[2][2] = 7; permanent[2][2] = false;
	board[2][3] = 2; permanent[2][3] = false;
	board[2][4] = 1; permanent[2][4] = true;
	board[2][5] = 9; permanent[2][5] = true;
	board[2][6] = 5; permanent[2][6] = true;
	board[2][7] = 3; permanent[2][7] = false;
	board[2][8] = 4; permanent[2][8] = false;
	board[2][9] = 8; permanent[2][9] = false;

	board[3][1] = 1; permanent[3][1] = false;
	board[3][2] = 9; permanent[3][2] = true;
	board[3][3] = 8; permanent[3][3] = true;
	board[3][4] = 3; permanent[3][4] = false;
	board[3][5] = 4; permanent[3][5] = false;
	board[3][6] = 2; permanent[3][6] = false;
	board[3][7] = 5; permanent[3][7] = false;
	board[3][8] = 6; permanent[3][8] = true;
	board[3][9] = 7; permanent[3][9] = false;

	board[4][1] = 8; permanent[4][1] = true;
	board[4][2] = 5; permanent[4][2] = false;
	board[4][3] = 9; permanent[4][3] = false;
	board[4][4] = 7; permanent[4][4] = false;
	board[4][5] = 6; permanent[4][5] = true;
	board[4][6] = 1; permanent[4][6] = false;
	board[4][7] = 4; permanent[4][7] = false;
	board[4][8] = 2; permanent[4][8] = false;
	board[4][9] = 3; permanent[4][9] = true;

	board[5][1] = 4; permanent[5][1] = true;
	board[5][2] = 2; permanent[5][2] = false;
	board[5][3] = 6; permanent[5][3] = false;
	board[5][4] = 8; permanent[5][4] = true;
	board[5][5] = 5; permanent[5][5] = false;
	board[5][6] = 3; permanent[5][6] = true;
	board[5][7] = 7; permanent[5][7] = false;
	board[5][8] = 9; permanent[5][8] = false;
	board[5][9] = 1; permanent[5][9] = true;

	board[6][1] = 7; permanent[6][1] = true;
	board[6][2] = 1; permanent[6][2] = false;
	board[6][3] = 3; permanent[6][3] = false;
	board[6][4] = 9; permanent[6][4] = false;
	board[6][5] = 2; permanent[6][5] = true;
	board[6][6] = 4; permanent[6][6] = false;
	board[6][7] = 8; permanent[6][7] = false;
	board[6][8] = 5; permanent[6][8] = false;
	board[6][9] = 6; permanent[6][9] = true;

	board[7][1] = 9; permanent[7][1] = false;
	board[7][2] = 6; permanent[7][2] = true;
	board[7][3] = 1; permanent[7][3] = false;
	board[7][4] = 5; permanent[7][4] = false;
	board[7][5] = 3; permanent[7][5] = false;
	board[7][6] = 7; permanent[7][6] = false;
	board[7][7] = 2; permanent[7][7] = true;
	board[7][8] = 8; permanent[7][8] = true;
	board[7][9] = 4; permanent[7][9] = false;

	board[8][1] = 2; permanent[8][1] = false;
	board[8][2] = 8; permanent[8][2] = false;
	board[8][3] = 7; permanent[8][3] = false;
	board[8][4] = 4; permanent[8][4] = true;
	board[8][5] = 1; permanent[8][5] = true;
	board[8][6] = 9; permanent[8][6] = true;
	board[8][7] = 6; permanent[8][7] = false;
	board[8][8] = 3; permanent[8][8] = false;
	board[8][9] = 5; permanent[8][9] = true;

	board[9][1] = 3; permanent[9][1] = false;
	board[9][2] = 4; permanent[9][2] = false;
	board[9][3] = 5; permanent[9][3] = false;
	board[9][4] = 2; permanent[9][4] = false;
	board[9][5] = 8; permanent[9][5] = true;
	board[9][6] = 6; permanent[9][6] = false;
	board[9][7] = 1; permanent[9][7] = false;
	board[9][8] = 7; permanent[9][8] = true;
	board[9][9] = 9; permanent[9][9] = true;
}
