//
//	Sudoku9by9SolverAnalyzer.cpp
//

bool Sudoku9by9SolverAnalyzer::Cell_Conflict_Check(int p, int i, int j)
{
	//
	//	Check along the containing Row
	//
	for (int k = 1; k <= 9; k++)
		if (board[i][k] == p) return false;

	//
	//	Check along the containing Column
	//
	for (int q = 1; q <= 9; q++)
		if (board[q][j] == p) return false;

	//
	//	Check left Column of the containing Box
	//
	if (j == 1 || j == 4 || j == 7)
	{
		//
		//	Check left upper Cell
		//
		if (i == 1 || i == 4 || i == 7))
		{
			if (board[i][j + 1] == p || board[i][j + 2] == p || board[i + 1][j] == p ||
				board[i + 2][j] == p || board[i + 1][j + 1] == p || board[i + 1][j + 2] == p ||
				board[i + 2][j + 1] == p || board[i + 2][j + 2] == p) return false;
		}

		//
		//	Check left middle Cell
		//
		else if (i == 2 || i == 5 || i == 8)
		{
			if (board[i - 1][j] == p || board[i + 1][j] == p || board[i - 1][j + 1] == p ||
				board[i][j + 1] == p || board[i + 1][j + 1] == p || board[i - 1][j + 2] == p ||
				board[i][j + 2] == p || board[i + 1][j + 2] == p) return false;
		}

		//
		//	Check left lower Cell
		//
		else if (i == 3 || i == 6 || i == 9)
		{
			if (board[i - 1][j] == p || board[i - 2][j] == p || board[i][j + 1] == p ||
				board[i][j + 2] == p || board[i - 1][j + 1] == p || board[i - 1][j + 2] == p ||
				board[i - 2][j + 1] == p || board[i - 2][j + 2] == p) return false;
		}
	}

	//
	//	Check middle Column of the containing Box
	//
	else if (j == 2 || j == 5 || j == 8)
	{
		//
		// Check middle upper Cell
		//
		if (i == 1 || i == 5 || i == 7))
		{
			if (board[i][j - 1] == p || board[i][j + 1] == p || board[i + 1][j - 1] == p ||
				board[i + 1][j] == p || board[i + 1][j + 1] == p || board[i + 2][j - 1] == p ||
				board[i + 2][j] == p || board[i + 2][j + 1] == p) return false;
		}

		//
		// Check middle middle Cell (center Cell of containing box)
		//
		else if (i == 2 || i == 5 || i == 8))
		{
			if (board[i - 1][j] == p || board[i - 1][j - 1] == p || board[i - 1][j + 1] == p ||
				board[i][j + 1] == p || board[i][j - 1] == p || board[i + 1][j - 1] == p ||
				board[i + 1][j] == p || board[i + 1][j + 1] == p) return false;
		}

		//
		// Check middle lower Cell
		//
		else if (i == 3 || i == 6 || i == 9)
		{
			if (board[i][j - 1] == p || board[i][j + 1] == p || board[i - 1][j] == p ||
				board[i - 1][j + 1] == p || board[i - 1][j - 1] == p || board[i - 2][j] == p ||
				board[i - 1][j + 1] == p || board[i - 2][j - 1] == p) return false;
		}
	}

	//
	//	Check right Column of containing Box
	//
	else if (j == 3 || j == 6 || j == 9)
	{
		//
		//	Check right upper Cell
		//
		if (i == 1 || i == 4 || i == 7))
		{
			if (board[i][j - 1] == p || board[i][j - 2] == p || board[i + 1][j] == p ||
				board[i + 1][j - 1] == p || board[i + 1][j - 2] == p || board[i + 2][j] == p ||
				board[i + 2][j - 1] == p || board[i + 2][j - 2] == p) return false;
		}

		//
		//	Check right middle Cell
		//
		else if (i == 2 || i == 5 || i == 8)
		{
			if (board[i - 1][j] == p || board[i - 1][j - 1] == p || board[i - 1][j - 2] == p ||
				board[i][j - 1] == p || board[i][j - 2] == p || board[i + 1][j] == p ||
				board[i + 1][j - 1] == p || board[i + 1][j - 2] == p) return false;
		}

		//
		//	Check right lower Cell
		//
		else if (i == 3 || i == 6 || i == 9))
		{
			if (board[i][j - 1] == p || board[i][j - 2] == p || board[i - 1][j] == p ||
				board[i - 1][j - 1] == p || board[i - 1][j - 2] == p || board[i - 2][j] == p ||
				board[i - 2][j - 1] == p || board[i - 2][j - 2] == p) return false;
		}
	}

	return true;
}

bool Sudoku9by9SolverAnalyzer::NextTryOrBackTrack(int i, int j, bool last_backtrack)
{
	int p;

	//	cout << "NextTryOrBackTrack Entry  :" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;

	if (permanent[i][j] == true)
	{
		if (last_backtrack)
		{
			//			cout << "NextTryOrBackTrack Exit 1a:" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;
			return true;
		}
		else {
			//			cout << "NextTryOrBackTrack Exit 1b:" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;
			return false;
		}
	}

	p = board[i][j];
	p++;

	while (p <= 9)
	{
		if (Game.Cell_Conflict_Check(p, i, j))
		{
			board[i][j] = p;
			//			cout << "NextTryOrBackTrack Exit 2 :" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;
			return false;
		}
		p++;
	}

	board[i][j] = 0;
	//	cout << "NextTryOrBackTrack Exit 3 :" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;
	return true;
}

void Sudoku9by9SolverAnalyzer::Solve()
{
	int i = 1, j = 1;
	bool backtrack = false;

	while (true)
	{
		while (i <= 9)
		{
			while (j <= 9)
			{
				backtrack = Game.NextTryOrBackTrack(i, j, backtrack);
				if (backtrack)
				{

					j = j - 1;

					if (j <= 0)
					{
						i = i - 1;
						j = 9;
					}

					if (i <= 0)
					{
						return;
					}
				}
				else
				{
					j++;
				}
			}

			j = 1;
			i++;
		}

		number_of_solutions++;

		cout << "Found a Solution: " << number_of_solutions << endl;

		Game.Print_Board();

		j = 9;
		i = 9;
		backtrack = true;
	}
}

int Sudoku9by9SolverAnalyzer::get_number_of_solutions(void)
{
	return number_of_solutions;
}
