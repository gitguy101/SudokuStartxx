//
//	Sudoku9by9SolverAnalyzer.cpp
//

bool Sudoku9by9SolverAnalyzer::Check_Conflicts(int p, int i, int j)
{
	for (int k = 1; k <= 9; k++)
		if (board[i][k] == p) return false;

	for (int q = 1; q <= 9; q++)
		if (board[q][j] == p) return false;

	/*
	*00
	000
	000
	*/
	if ((j == 1 || j == 4 || j == 7) && (i == 1 || i == 4 || i == 7))
	{
		if (board[i][j + 1] == p || board[i][j + 2] == p || board[i + 1][j] == p ||
			board[i + 2][j] == p || board[i + 1][j + 1] == p || board[i + 1][j + 2] == p ||
			board[i + 2][j + 1] == p || board[i + 2][j + 2] == p) return false;
	}

	/*
	000
	*00
	000
	*/
	if ((j == 1 || j == 4 || j == 7) && (i == 2 || i == 5 || i == 8))
	{
		if (board[i - 1][j] == p || board[i + 1][j] == p || board[i - 1][j + 1] == p ||
			board[i][j + 1] == p || board[i + 1][j + 1] == p || board[i - 1][j + 2] == p ||
			board[i][j + 2] == p || board[i + 1][j + 2] == p) return false;
	}

	/*
	000
	000
	*00
	*/
	if ((j == 1 || j == 4 || j == 7) && (i == 3 || i == 6 || i == 9))
	{
		if (board[i - 1][j] == p || board[i - 2][j] == p || board[i][j + 1] == p ||
			board[i][j + 2] == p || board[i - 1][j + 1] == p || board[i - 1][j + 2] == p ||
			board[i - 2][j + 1] == p || board[i - 2][j + 2] == p) return false;
	}

	/*
	0*0
	000
	000
	*/
	if ((j == 2 || j == 5 || j == 8) && (i == 1 || i == 5 || i == 7))
	{
		if (board[i][j - 1] == p || board[i][j + 1] == p || board[i + 1][j - 1] == p ||
			board[i + 1][j] == p || board[i + 1][j + 1] == p || board[i + 2][j - 1] == p ||
			board[i + 2][j] == p || board[i + 2][j + 1] == p) return false;
	}

	/*
	000
	0*0
	000
	*/
	if ((j == 2 || j == 5 || j == 8) && (i == 2 || i == 5 || i == 8))
	{
		if (board[i - 1][j] == p || board[i - 1][j - 1] == p || board[i - 1][j + 1] == p ||
			board[i][j + 1] == p || board[i][j - 1] == p || board[i + 1][j - 1] == p ||
			board[i + 1][j] == p || board[i + 1][j + 1] == p)return false;
	}

	/*
	000
	000
	0*0
	*/
	if ((j == 2 || j == 5 || j == 8) && (i == 3 || i == 6 || i == 9))
	{
		if (board[i][j - 1] == p || board[i][j + 1] == p || board[i - 1][j] == p ||
			board[i - 1][j + 1] == p || board[i - 1][j - 1] == p || board[i - 2][j] == p ||
			board[i - 1][j + 1] == p || board[i - 2][j - 1] == p) return false;
	}

	/*
	00*
	000
	000
	*/
	if ((j == 3 || j == 6 || j == 9) && (i == 1 || i == 4 || i == 7))
	{
		if (board[i][j - 1] == p || board[i][j - 2] == p || board[i + 1][j] == p ||
			board[i + 1][j - 1] == p || board[i + 1][j - 2] == p || board[i + 2][j] == p ||
			board[i + 2][j - 1] == p || board[i + 2][j - 2] == p) return false;
	}

	/*
	000
	00*
	000
	*/
	if ((j == 3 || j == 6 || j == 9) && (i == 2 || i == 5 || i == 8))
	{
		if (board[i - 1][j] == p || board[i - 1][j - 1] == p || board[i - 1][j - 2] == p ||
			board[i][j - 1] == p || board[i][j - 2] == p || board[i + 1][j] == p ||
			board[i + 1][j - 1] == p || board[i + 1][j - 2] == p) return false;
	}

	/*
	000
	000
	00*
	*/
	if ((j == 3 || j == 6 || j == 9) && (i == 3 || i == 6 || i == 9))
	{
		if (board[i][j - 1] == p || board[i][j - 2] == p || board[i - 1][j] == p ||
			board[i - 1][j - 1] == p || board[i - 1][j - 2] == p || board[i - 2][j] == p ||
			board[i - 2][j - 1] == p || board[i - 2][j - 2] == p) return false;
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
		if (Game.Check_Conflicts(p, i, j))
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
