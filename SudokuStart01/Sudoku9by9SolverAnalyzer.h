//
//	Sudoku 9by9 Solver and Analyzer
//

#include "Sudoku9by9Board.h"

class Sudoku9by9SolverAnalyzer
{
private:
	Sudoku9by9Board *board_ptr;
	int number_of_solutions;
public:
	Sudoku9by9SolverAnalyzer();
	Sudoku9by9SolverAnalyzer(Sudoku9by9Board *board_ptr);
	bool NextTryOrBackTrack(int i, int j, bool backtrack);
	void Solve(void);
	bool Check_Conflicts(int p, int i, int j);
	int get_number_of_solutions(void);
	~Sudoku9by9SolverAnalyzer();
};