//
//	Sudoku9by9PuzzleBoard.h
//


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
	status_t WriteCell(int row, int column, int cell_value);
	void Print_PuzzleBoard();
	void BuiltInUnitTest01Puzzle();
	void BuiltInUnitTest01Solution();
	~Sudoku9by9PuzzleBoard();
};

