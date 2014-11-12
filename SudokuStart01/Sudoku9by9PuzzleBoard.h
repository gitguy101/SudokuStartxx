//
//	Sudoku9by9PuzzleBoard.h
//

#ifndef SUDOKU9BY9PUZZLEBOARD_H
#define SUDOKU9BY9PUZZLEBOARD_H

#define NOSFUNTC_NOTSET -1
#define SUDOKU_SUCCESS 0

typedef int status_t;

class Sudoku9by9PuzzleBoard
{
private:
	int cells[10][10];
	bool permanent_cells[10][10];
	int number_of_solutions_for_unit_test_check;
public:
	Sudoku9by9PuzzleBoard();

	int ReadCell(int row, int column);
	bool ReadPermanent(int row, int column);
	status_t WriteCell(int row, int column, int cell_value);

	void Print_PuzzleBoard();

	void BuiltInUnitTest01Puzzle();
	void BuiltInUnitTest01Solution();
	void BuiltInUnitTest02Puzzle();
	void BuiltInUnitTest02Solution();
	void BuiltInUnitTest03Puzzle();
	void BuiltInUnitTest03Solution();

	void set_number_of_solutions_for_unit_test_check(int);
	void increment_number_of_solutions_for_unit_test_check(void);
	int read_number_of_solutions_for_unit_test_check(void);

	~Sudoku9by9PuzzleBoard();
};

#endif