//
// Main for testing
//


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

#include "Sudoku9by9PuzzleBoard.h"
#include "Sudoku9by9SolverAnalyzer.h"

Sudoku9by9PuzzleBoard PuzzleTestSubject001;
Sudoku9by9SolverAnalyzer SolverTestSubject001(&PuzzleTestSubject001);

int _tmain(int argc, _TCHAR* argv[])
{
	PuzzleTestSubject001.BuiltInUnitTest01Puzzle();
	PuzzleTestSubject001.Print_PuzzleBoard();

	SolverTestSubject001.Solve();

	if (SolverTestSubject001.get_number_of_solutions() == 0)
	{
		cout << "No Solutions" << endl;
	}
	else if (SolverTestSubject001.get_number_of_solutions() == 1)
	{
		cout << "One unique solution!" << endl;
	}
	else if (SolverTestSubject001.get_number_of_solutions() > 1)
	{
		cout << "Too many solutions: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}
	else
	{
		cout << "Error: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}

	PuzzleTestSubject001.Print_PuzzleBoard();

	system("pause");

	return 0;
}
