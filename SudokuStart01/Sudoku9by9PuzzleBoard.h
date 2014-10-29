//
//	Sudoku9by9PuzzleBoard.h
//


#define NOSFUNTC_NOTSET -1

class Sudoku9by9PuzzleBoard
{
private:
	int board[10][10];
	bool permanent[10][10];
	int number_of_solutions_for_unit_test_check;
public:
	Sudoku9by9PuzzleBoard();
	void Print_PuzzleBoard();
	void BuiltInUnitTest01Puzzle();
	void BuiltInUnitTest01Solution();
	~Sudoku9by9PuzzleBoard();
};

