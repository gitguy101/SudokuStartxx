//
//	Sudoku 9by9 Solver and Analyzer
//

#ifndef SUDOKU9BY9SOLVERANALYZER_H
#define SUDOKU9BY9SOLVERANALYZER_H

#include "Sudoku9by9PuzzleBoard.h"

class Sudoku9by9SolverAnalyzer
{
private:
	Sudoku9by9PuzzleBoard *puzzle_board_ptr;
	int number_of_solutions;
public:
	Sudoku9by9SolverAnalyzer();
	Sudoku9by9SolverAnalyzer(Sudoku9by9PuzzleBoard *passed_puzzle_board_ptr);

	int ReadCell(int row, int column);
	bool ReadPermanent(int row, int column);
	status_t WriteCell(int row, int column, int cell_value);

	bool NextTryOrBackTrack(int i, int j, bool backtrack);
	void Solve(void);
	bool Cell_Conflict_Check(int p, int i, int j);
	int get_number_of_solutions(void);

	~Sudoku9by9SolverAnalyzer();
};

#endif