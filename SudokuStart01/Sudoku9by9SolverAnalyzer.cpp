//
//	Sudoku9by9SolverAnalyzer.cpp
//

//TODO: get rid of this, add ability to save all solutions in some way 

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;


#include "Sudoku9by9SolverAnalyzer.h"

Sudoku9by9SolverAnalyzer::Sudoku9by9SolverAnalyzer()
{
	number_of_solutions = 0;
}

Sudoku9by9SolverAnalyzer::Sudoku9by9SolverAnalyzer(Sudoku9by9PuzzleBoard *passed_puzzle_board_ptr)
{
	number_of_solutions = 0;

	puzzle_board_ptr = passed_puzzle_board_ptr;
}

int Sudoku9by9SolverAnalyzer::ReadCell(int row, int column)
{
	return(puzzle_board_ptr->ReadCell(row, column));
}

bool Sudoku9by9SolverAnalyzer::ReadPermanent(int row, int column)
{
	return(puzzle_board_ptr->ReadPermanent(row, column));
}

status_t Sudoku9by9SolverAnalyzer::WriteCell(int row, int column, int cell_value)
{
	return(puzzle_board_ptr->WriteCell(row, column, cell_value));
}

bool Sudoku9by9SolverAnalyzer::Cell_Conflict_Check(int cell_value, int row, int column)
{
	//
	//	Check along the containing Row
	//
	for (int i = 1; i <= 9; i++)
		if (ReadCell(row, i) == cell_value) return false;

	//
	//	Check along the containing Column
	//
	for (int i = 1; i <= 9; i++)
		if (ReadCell(i, column) == cell_value) return false;

	//
	//	Check left Column of the containing Box
	//
	if (column == 1 || column == 4 || column == 7)
	{
		//
		//	Check left upper Cell
		//
		if (row == 1 || row == 4 || row == 7)
		{
			if (ReadCell(row, column + 1) == cell_value || ReadCell(row, column + 2) == cell_value || ReadCell(row + 1, column) == cell_value ||
				ReadCell(row + 2, column) == cell_value || ReadCell(row + 1, column + 1) == cell_value || ReadCell(row + 1, column + 2) == cell_value ||
				ReadCell(row + 2, column + 1) == cell_value || ReadCell(row + 2, column + 2) == cell_value) return false;
		}

		//
		//	Check left middle Cell
		//
		else if (row == 2 || row == 5 || row == 8)
		{
			if (ReadCell(row - 1, column) == cell_value || ReadCell(row + 1, column) == cell_value || ReadCell(row - 1, column + 1) == cell_value ||
				ReadCell(row, column + 1) == cell_value || ReadCell(row + 1, column + 1) == cell_value || ReadCell(row - 1, column + 2) == cell_value ||
				ReadCell(row, column + 2) == cell_value || ReadCell(row + 1, column + 2) == cell_value) return false;
		}

		//
		//	Check left lower Cell
		//
		else if (row == 3 || row == 6 || row == 9)
		{
			if (ReadCell(row - 1, column) == cell_value || ReadCell(row - 2, column) == cell_value || ReadCell(row, column + 1) == cell_value ||
				ReadCell(row, column + 2) == cell_value || ReadCell(row - 1, column + 1) == cell_value || ReadCell(row - 1, column + 2) == cell_value ||
				ReadCell(row - 2, column + 1) == cell_value || ReadCell(row - 2, column + 2) == cell_value) return false;
		}
	}

	//
	//	Check middle Column of the containing Box
	//
	else if (column == 2 || column == 5 || column == 8)
	{
		//
		// Check middle upper Cell
		//
		if (row == 1 || row == 5 || row == 7)
		{
			if (ReadCell(row, column - 1) == cell_value || ReadCell(row, column + 1) == cell_value || ReadCell(row + 1, column - 1) == cell_value ||
				ReadCell(row + 1, column) == cell_value || ReadCell(row + 1, column + 1) == cell_value || ReadCell(row + 2, column - 1) == cell_value ||
				ReadCell(row + 2, column) == cell_value || ReadCell(row + 2, column + 1) == cell_value) return false;
		}

		//
		// Check middle middle Cell (center Cell of containing box)
		//
		else if (row == 2 || row == 5 || row == 8)
		{
			if (ReadCell(row - 1, column) == cell_value || ReadCell(row - 1, column - 1) == cell_value || ReadCell(row - 1, column + 1) == cell_value ||
				ReadCell(row, column + 1) == cell_value || ReadCell(row, column - 1) == cell_value || ReadCell(row + 1, column - 1) == cell_value ||
				ReadCell(row + 1, column) == cell_value || ReadCell(row + 1, column + 1) == cell_value) return false;
		}

		//
		// Check middle lower Cell
		//
		else if (row == 3 || row == 6 || row == 9)
		{
			if (ReadCell(row, column - 1) == cell_value || ReadCell(row, column + 1) == cell_value || ReadCell(row - 1, column) == cell_value ||
				ReadCell(row - 1, column + 1) == cell_value || ReadCell(row - 1, column - 1) == cell_value || ReadCell(row - 2, column) == cell_value ||
				ReadCell(row - 1, column + 1) == cell_value || ReadCell(row - 2, column - 1) == cell_value) return false;
		}
	}

	//
	//	Check right Column of containing Box
	//
	else if (column == 3 || column == 6 || column == 9)
	{
		//
		//	Check right upper Cell
		//
		if (row == 1 || row == 4 || row == 7)
		{
			if (ReadCell(row, column - 1) == cell_value || ReadCell(row, column - 2) == cell_value || ReadCell(row + 1, column) == cell_value ||
				ReadCell(row + 1, column - 1) == cell_value || ReadCell(row + 1, column - 2) == cell_value || ReadCell(row + 2, column) == cell_value ||
				ReadCell(row + 2, column - 1) == cell_value || ReadCell(row + 2, column - 2) == cell_value) return false;
		}

		//
		//	Check right middle Cell
		//
		else if (row == 2 || row == 5 || row == 8)
		{
			if (ReadCell(row - 1, column) == cell_value || ReadCell(row - 1, column - 1) == cell_value || ReadCell(row - 1, column - 2) == cell_value ||
				ReadCell(row, column - 1) == cell_value || ReadCell(row, column - 2) == cell_value || ReadCell(row + 1, column) == cell_value ||
				ReadCell(row + 1, column - 1) == cell_value || ReadCell(row + 1, column - 2) == cell_value) return false;
		}

		//
		//	Check right lower Cell
		//
		else if (row == 3 || row == 6 || row == 9)
		{
			if (ReadCell(row, column - 1) == cell_value || ReadCell(row, column - 2) == cell_value || ReadCell(row - 1, column) == cell_value ||
				ReadCell(row - 1, column - 1) == cell_value || ReadCell(row - 1, column - 2) == cell_value || ReadCell(row - 2, column) == cell_value ||
				ReadCell(row - 2, column - 1) == cell_value || ReadCell(row - 2, column - 2) == cell_value) return false;
		}
	}

	return true;
}

bool Sudoku9by9SolverAnalyzer::NextTryOrBackTrack(int row, int column, bool last_backtrack)
{
	int cell_value;

	//	cout << "NextTryOrBackTrack Entry  :" << row << " " << column << " " << ReadCell(row, column) << " " << ReadPermanent(row, column) << endl;

	if (ReadPermanent(row, column) == true)
	{
		if (last_backtrack)
		{
			//			cout << "NextTryOrBackTrack Exit 1a:" << row << " " << column << " " << ReadCell(row, column) << " " << ReadPermanent(row, column) << endl;
			return true;
		}
		else {
			//			cout << "NextTryOrBackTrack Exit 1b:" << row << " " << column << " " << ReadCell(row, column) << " " << ReadPermanent(row, column) << endl;
			return false;
		}
	}

	cell_value = ReadCell(row, column);
	cell_value++;

	while (cell_value <= 9)
	{
		if (Cell_Conflict_Check(cell_value, row, column))
		{
			WriteCell(row, column, cell_value);
			//			cout << "NextTryOrBackTrack Exit 2 :" << row << " " << column << " " << ReadCell(row, column) << " " << ReadPermanent(row, column) << endl;
			return false;
		}
		cell_value++;
	}

	WriteCell(row, column, 0);
	//	cout << "NextTryOrBackTrack Exit 3 :" << row << " " << column << " " << ReadCell(row, column) << " " << ReadPermanent(row, column) << endl;
	return true;
}

void Sudoku9by9SolverAnalyzer::Solve()
{
	int row = 1, column = 1;
	bool backtrack = false;

	puzzle_board_ptr->set_number_of_solutions_for_unit_test_check(0);

	while (true)
	{
		while (row <= 9)
		{
			while (column <= 9)
			{
				backtrack = NextTryOrBackTrack(row, column, backtrack);
				if (backtrack)
				{

					column = column - 1;

					if (column <= 0)
					{
						row = row - 1;
						column = 9;
					}

					if (row <= 0)
					{
						return;
					}
				}
				else
				{
					column++;
				}
			}

			column = 1;
			row++;
		}

		number_of_solutions++;
		puzzle_board_ptr->increment_number_of_solutions_for_unit_test_check();

		cout << "Found a Solution: " << number_of_solutions << endl;

		puzzle_board_ptr->Print_PuzzleBoard();

		column = 9;
		row = 9;
		backtrack = true;
	}
}

int Sudoku9by9SolverAnalyzer::get_number_of_solutions(void)
{
	return number_of_solutions;
}


Sudoku9by9SolverAnalyzer::~Sudoku9by9SolverAnalyzer(void) {}