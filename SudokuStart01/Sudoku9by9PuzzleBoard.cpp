//
// Sudoku9by9PuzzleBoard.cpp
//

#include "Sudoku9by9PuzzleBoard.h"

Sudoku9by9PuzzleBoard::Sudoku9by9PuzzleBoard()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
		cells[i][j] = 0;
		permanent_cells[i][j] = false;
		}

	number_of_solutions_for_unit_test_check = NOSFUNTC_NOTSET;		/* Not set yet */
}

int ReadCell(int row, int column)
{
	return(cells[row][column]);
}

int ReadPermanent(int row, int column)
{
	return(permanent[row][column]);
}

status_t WriteCell(int row, int column, int cell_value)
{
	cells[row][column] = cell_value;
	return SUDOKU_SUCCESS;
}

void Sudoku9by9PuzzleBoard::Print_PuzzleBoard()
{
	cout << endl << "--+------+-------+---------" << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << "  |";

		for (int j = 1; j <= 9; j++)
		{
			if (permanent_cells[i][j] == true)
			{
				setcolor(12);
				cout << cells[i][j] << " ";
				setcolor(7);
			}
			else cout << cells[i][j] << " ";
			if (j % 3 == 0) cout << "| ";
		}

		cout << endl;

		if (i % 3 == 0) cout << "--+------+-------+---------" << endl;
	}
}

void Sudoku9by9PuzzleBoard::BuiltInUnitTest01Puzzle()
{
	cells[1][1] = 5; permanent_cells[1][1] = true;
	cells[1][2] = 3; permanent_cells[1][2] = true;
	cells[1][5] = 7; permanent_cells[1][5] = true;

	cells[2][1] = 6; permanent_cells[2][1] = true;
	cells[2][4] = 1; permanent_cells[2][4] = true;
	cells[2][5] = 9; permanent_cells[2][5] = true;
	cells[2][6] = 5; permanent_cells[2][6] = true;

	cells[3][2] = 9; permanent_cells[3][2] = true;
	cells[3][3] = 8; permanent_cells[3][3] = true;
	cells[3][8] = 6; permanent_cells[3][8] = true;

	cells[4][1] = 8; permanent_cells[4][1] = true;
	cells[4][5] = 6; permanent_cells[4][5] = true;
	cells[4][9] = 3; permanent_cells[4][9] = true;

	cells[5][1] = 4; permanent_cells[5][1] = true;
	cells[5][4] = 8; permanent_cells[5][4] = true;
	cells[5][6] = 3; permanent_cells[5][6] = true;
	cells[5][9] = 1; permanent_cells[5][9] = true;

	cells[6][1] = 7; permanent_cells[6][1] = true;
	cells[6][5] = 2; permanent_cells[6][5] = true;
	cells[6][9] = 6; permanent_cells[6][9] = true;

	cells[7][2] = 6; permanent_cells[7][2] = true;
	cells[7][7] = 2; permanent_cells[7][7] = true;
	cells[7][8] = 8; permanent_cells[7][8] = true;

	cells[8][4] = 4; permanent_cells[8][4] = true;
	cells[8][5] = 1; permanent_cells[8][5] = true;
	cells[8][6] = 9; permanent_cells[8][6] = true;
	cells[8][9] = 5; permanent_cells[8][9] = true;

	cells[9][5] = 8; permanent_cells[9][5] = true;
	cells[9][8] = 7; permanent_cells[9][8] = true;
	cells[9][9] = 9; permanent_cells[9][9] = true;
}

void Sudoku9by9PuzzleBoard::BuiltInUnitTest01Solution()
{
	number_of_solutions_for_unit_test_check = 1;		/* one unique solution */

	cells[1][1] = 5; permanent_cells[1][1] = true;
	cells[1][2] = 3; permanent_cells[1][2] = true;
	cells[1][3] = 4; permanent_cells[1][3] = false;
	cells[1][4] = 6; permanent_cells[1][4] = false;
	cells[1][5] = 7; permanent_cells[1][5] = true;
	cells[1][6] = 8; permanent_cells[1][6] = false;
	cells[1][7] = 9; permanent_cells[1][7] = false;
	cells[1][8] = 1; permanent_cells[1][8] = false;
	cells[1][9] = 2; permanent_cells[1][9] = false;

	cells[2][1] = 6; permanent_cells[2][1] = true;
	cells[2][2] = 7; permanent_cells[2][2] = false;
	cells[2][3] = 2; permanent_cells[2][3] = false;
	cells[2][4] = 1; permanent_cells[2][4] = true;
	cells[2][5] = 9; permanent_cells[2][5] = true;
	cells[2][6] = 5; permanent_cells[2][6] = true;
	cells[2][7] = 3; permanent_cells[2][7] = false;
	cells[2][8] = 4; permanent_cells[2][8] = false;
	cells[2][9] = 8; permanent_cells[2][9] = false;

	cells[3][1] = 1; permanent_cells[3][1] = false;
	cells[3][2] = 9; permanent_cells[3][2] = true;
	cells[3][3] = 8; permanent_cells[3][3] = true;
	cells[3][4] = 3; permanent_cells[3][4] = false;
	cells[3][5] = 4; permanent_cells[3][5] = false;
	cells[3][6] = 2; permanent_cells[3][6] = false;
	cells[3][7] = 5; permanent_cells[3][7] = false;
	cells[3][8] = 6; permanent_cells[3][8] = true;
	cells[3][9] = 7; permanent_cells[3][9] = false;

	cells[4][1] = 8; permanent_cells[4][1] = true;
	cells[4][2] = 5; permanent_cells[4][2] = false;
	cells[4][3] = 9; permanent_cells[4][3] = false;
	cells[4][4] = 7; permanent_cells[4][4] = false;
	cells[4][5] = 6; permanent_cells[4][5] = true;
	cells[4][6] = 1; permanent_cells[4][6] = false;
	cells[4][7] = 4; permanent_cells[4][7] = false;
	cells[4][8] = 2; permanent_cells[4][8] = false;
	cells[4][9] = 3; permanent_cells[4][9] = true;

	cells[5][1] = 4; permanent_cells[5][1] = true;
	cells[5][2] = 2; permanent_cells[5][2] = false;
	cells[5][3] = 6; permanent_cells[5][3] = false;
	cells[5][4] = 8; permanent_cells[5][4] = true;
	cells[5][5] = 5; permanent_cells[5][5] = false;
	cells[5][6] = 3; permanent_cells[5][6] = true;
	cells[5][7] = 7; permanent_cells[5][7] = false;
	cells[5][8] = 9; permanent_cells[5][8] = false;
	cells[5][9] = 1; permanent_cells[5][9] = true;

	cells[6][1] = 7; permanent_cells[6][1] = true;
	cells[6][2] = 1; permanent_cells[6][2] = false;
	cells[6][3] = 3; permanent_cells[6][3] = false;
	cells[6][4] = 9; permanent_cells[6][4] = false;
	cells[6][5] = 2; permanent_cells[6][5] = true;
	cells[6][6] = 4; permanent_cells[6][6] = false;
	cells[6][7] = 8; permanent_cells[6][7] = false;
	cells[6][8] = 5; permanent_cells[6][8] = false;
	cells[6][9] = 6; permanent_cells[6][9] = true;

	cells[7][1] = 9; permanent_cells[7][1] = false;
	cells[7][2] = 6; permanent_cells[7][2] = true;
	cells[7][3] = 1; permanent_cells[7][3] = false;
	cells[7][4] = 5; permanent_cells[7][4] = false;
	cells[7][5] = 3; permanent_cells[7][5] = false;
	cells[7][6] = 7; permanent_cells[7][6] = false;
	cells[7][7] = 2; permanent_cells[7][7] = true;
	cells[7][8] = 8; permanent_cells[7][8] = true;
	cells[7][9] = 4; permanent_cells[7][9] = false;

	cells[8][1] = 2; permanent_cells[8][1] = false;
	cells[8][2] = 8; permanent_cells[8][2] = false;
	cells[8][3] = 7; permanent_cells[8][3] = false;
	cells[8][4] = 4; permanent_cells[8][4] = true;
	cells[8][5] = 1; permanent_cells[8][5] = true;
	cells[8][6] = 9; permanent_cells[8][6] = true;
	cells[8][7] = 6; permanent_cells[8][7] = false;
	cells[8][8] = 3; permanent_cells[8][8] = false;
	cells[8][9] = 5; permanent_cells[8][9] = true;

	cells[9][1] = 3; permanent_cells[9][1] = false;
	cells[9][2] = 4; permanent_cells[9][2] = false;
	cells[9][3] = 5; permanent_cells[9][3] = false;
	cells[9][4] = 2; permanent_cells[9][4] = false;
	cells[9][5] = 8; permanent_cells[9][5] = true;
	cells[9][6] = 6; permanent_cells[9][6] = false;
	cells[9][7] = 1; permanent_cells[9][7] = false;
	cells[9][8] = 7; permanent_cells[9][8] = true;
	cells[9][9] = 9; permanent_cells[9][9] = true;
}
