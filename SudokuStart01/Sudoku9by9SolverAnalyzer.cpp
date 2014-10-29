//
//	Sudoku9by9SolverAnalyzer.cpp
//

bool Sudoku9by9SolverAnalyzer::Cell_Conflict_Check(int cell_value, int row, int column)
{
	//
	//	Check along the containing Row
	//
	for (int i = 1; i <= 9; i++)
		if (board[row][i] == cell_value) return false;

	//
	//	Check along the containing Column
	//
	for (int i = 1; i <= 9; i++)
		if (board[i][column] == cell_value) return false;

	//
	//	Check left Column of the containing Box
	//
	if (column == 1 || column == 4 || column == 7)
	{
		//
		//	Check left upper Cell
		//
		if (row == 1 || row == 4 || row == 7))
		{
			if (board[row][column + 1] == cell_value || board[row][column + 2] == cell_value || board[row + 1][column] == cell_value ||
				board[row + 2][column] == cell_value || board[row + 1][column + 1] == cell_value || board[row + 1][column + 2] == cell_value ||
				board[row + 2][column + 1] == cell_value || board[row + 2][column + 2] == cell_value) return false;
		}

		//
		//	Check left middle Cell
		//
		else if (row == 2 || row == 5 || row == 8)
		{
			if (board[row - 1][column] == cell_value || board[row + 1][column] == cell_value || board[row - 1][column + 1] == cell_value ||
				board[row][column + 1] == cell_value || board[row + 1][column + 1] == cell_value || board[row - 1][column + 2] == cell_value ||
				board[row][column + 2] == cell_value || board[row + 1][column + 2] == cell_value) return false;
		}

		//
		//	Check left lower Cell
		//
		else if (row == 3 || row == 6 || row == 9)
		{
			if (board[row - 1][column] == cell_value || board[row - 2][column] == cell_value || board[row][column + 1] == cell_value ||
				board[row][column + 2] == cell_value || board[row - 1][column + 1] == cell_value || board[row - 1][column + 2] == cell_value ||
				board[row - 2][column + 1] == cell_value || board[row - 2][column + 2] == cell_value) return false;
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
		if (row == 1 || row == 5 || row == 7))
		{
			if (board[row][column - 1] == cell_value || board[row][column + 1] == cell_value || board[row + 1][column - 1] == cell_value ||
				board[row + 1][column] == cell_value || board[row + 1][column + 1] == cell_value || board[row + 2][column - 1] == cell_value ||
				board[row + 2][column] == cell_value || board[row + 2][column + 1] == cell_value) return false;
		}

		//
		// Check middle middle Cell (center Cell of containing box)
		//
		else if (row == 2 || row == 5 || row == 8))
		{
			if (board[row - 1][column] == cell_value || board[row - 1][column - 1] == cell_value || board[row - 1][column + 1] == cell_value ||
				board[row][column + 1] == cell_value || board[row][column - 1] == cell_value || board[row + 1][column - 1] == cell_value ||
				board[row + 1][column] == cell_value || board[row + 1][column + 1] == cell_value) return false;
		}

		//
		// Check middle lower Cell
		//
		else if (row == 3 || row == 6 || row == 9)
		{
			if (board[row][column - 1] == cell_value || board[row][column + 1] == cell_value || board[row - 1][column] == cell_value ||
				board[row - 1][column + 1] == cell_value || board[row - 1][column - 1] == cell_value || board[row - 2][column] == cell_value ||
				board[row - 1][column + 1] == cell_value || board[row - 2][column - 1] == cell_value) return false;
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
		if (row == 1 || row == 4 || row == 7))
		{
			if (board[row][column - 1] == cell_value || board[row][column - 2] == cell_value || board[row + 1][column] == cell_value ||
				board[row + 1][column - 1] == cell_value || board[row + 1][column - 2] == cell_value || board[row + 2][column] == cell_value ||
				board[row + 2][column - 1] == cell_value || board[row + 2][column - 2] == cell_value) return false;
		}

		//
		//	Check right middle Cell
		//
		else if (row == 2 || row == 5 || row == 8)
		{
			if (board[row - 1][column] == cell_value || board[row - 1][column - 1] == cell_value || board[row - 1][column - 2] == cell_value ||
				board[row][column - 1] == cell_value || board[row][column - 2] == cell_value || board[row + 1][column] == cell_value ||
				board[row + 1][column - 1] == cell_value || board[row + 1][column - 2] == cell_value) return false;
		}

		//
		//	Check right lower Cell
		//
		else if (row == 3 || row == 6 || row == 9))
		{
			if (board[row][column - 1] == cell_value || board[row][column - 2] == cell_value || board[row - 1][column] == cell_value ||
				board[row - 1][column - 1] == cell_value || board[row - 1][column - 2] == cell_value || board[row - 2][column] == cell_value ||
				board[row - 2][column - 1] == cell_value || board[row - 2][column - 2] == cell_value) return false;
		}
	}

	return true;
}

bool Sudoku9by9SolverAnalyzer::NextTryOrBackTrack(int row, int column, bool last_backtrack)
{
	int cell_value;

	//	cout << "NextTryOrBackTrack Entry  :" << row << " " << column << " " << board[row][column] << " " << permanent[row][column] << endl;

	if (permanent[row][column] == true)
	{
		if (last_backtrack)
		{
			//			cout << "NextTryOrBackTrack Exit 1a:" << row << " " << column << " " << board[row][column] << " " << permanent[row][column] << endl;
			return true;
		}
		else {
			//			cout << "NextTryOrBackTrack Exit 1b:" << row << " " << column << " " << board[row][column] << " " << permanent[row][column] << endl;
			return false;
		}
	}

	cell_value = board[row][column];
	cell_value++;

	while (cell_value <= 9)
	{
		if (Game.Cell_Conflict_Check(cell_value, row, column))
		{
			board[row][column] = cell_value;
			//			cout << "NextTryOrBackTrack Exit 2 :" << row << " " << column << " " << board[row][column] << " " << permanent[row][column] << endl;
			return false;
		}
		cell_value++;
	}

	board[row][column] = 0;
	//	cout << "NextTryOrBackTrack Exit 3 :" << row << " " << column << " " << board[row][column] << " " << permanent[row][column] << endl;
	return true;
}

void Sudoku9by9SolverAnalyzer::Solve()
{
	int row = 1, column = 1;
	bool backtrack = false;

	while (true)
	{
		while (row <= 9)
		{
			while (column <= 9)
			{
				backtrack = Game.NextTryOrBackTrack(row, column, backtrack);
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

		cout << "Found a Solution: " << number_of_solutions << endl;

		Game.Print_Board();

		column = 9;
		row = 9;
		backtrack = true;
	}
}

int Sudoku9by9SolverAnalyzer::get_number_of_solutions(void)
{
	return number_of_solutions;
}
