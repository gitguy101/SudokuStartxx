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

Sudoku9by9PuzzleBoard PuzzleTestSubject002;
Sudoku9by9SolverAnalyzer SolverTestSubject002(&PuzzleTestSubject002);

Sudoku9by9PuzzleBoard PuzzleTestSubject003;
Sudoku9by9SolverAnalyzer SolverTestSubject003(&PuzzleTestSubject003);

int _tmain(int argc, _TCHAR* argv[])
{
	//
	// Test 1
	//
	cout << "Test 01" << endl;

	PuzzleTestSubject001.BuiltInUnitTest01Puzzle();
	PuzzleTestSubject001.Print_PuzzleBoard();

	SolverTestSubject001.Solve();

	if (SolverTestSubject001.get_number_of_solutions() == 0)
	{
		cout << "Failed: No Solutions" << endl;
	}
	else if (SolverTestSubject001.get_number_of_solutions() == 1)
	{
		cout << "Passed: One unique solution!" << endl;
	}
	else if (SolverTestSubject001.get_number_of_solutions() > 1)
	{
		cout << "Failed: Too many solutions: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}
	else
	{
		cout << "Error: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}

	//
	// Test 2
	//
	cout << endl << "Test 02" << endl;

	PuzzleTestSubject002.BuiltInUnitTest02Puzzle();
	PuzzleTestSubject002.Print_PuzzleBoard();

	SolverTestSubject002.Solve();

	if (SolverTestSubject002.get_number_of_solutions() == 0)
	{
		cout << "Failed: No Solutions" << endl;
	}
	else if (SolverTestSubject002.get_number_of_solutions() == 1)
	{
		cout << "Failed: One unique solution!" << endl;
	}
	else if (SolverTestSubject002.get_number_of_solutions() == 2)
	{
		cout << "Passed: Two solutions: " << SolverTestSubject002.get_number_of_solutions() << endl;
	}
	else if (SolverTestSubject002.get_number_of_solutions() > 2)
	{
		cout << "Failed: Two solutions: " << SolverTestSubject002.get_number_of_solutions() << endl;
	}
	else
	{
		cout << "Error: " << SolverTestSubject002.get_number_of_solutions() << endl;
	}

	//
	// Test 3
	//
	cout << endl << "Test 03" << endl;

	PuzzleTestSubject003.BuiltInUnitTest03Puzzle();
	PuzzleTestSubject003.Print_PuzzleBoard();

	SolverTestSubject003.Solve();

	if (SolverTestSubject003.get_number_of_solutions() == 0)
	{
		cout << "Passed: No Solutions" << endl;
	}
	else if (SolverTestSubject003.get_number_of_solutions() == 1)
	{
		cout << "Failed: One unique solution!" << endl;
	}
	else if (SolverTestSubject001.get_number_of_solutions() > 1)
	{
		cout << "Failed: Too many solutions: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}
	else
	{
		cout << "Error: " << SolverTestSubject001.get_number_of_solutions() << endl;
	}

	return 0;
}
