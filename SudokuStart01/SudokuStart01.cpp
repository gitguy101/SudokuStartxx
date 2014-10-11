// SudokuStart01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Sudoku
{
private:
	int board[10][10];
	bool permanent[10][10];
	int number_of_solutions;
public:
	Sudoku();
	void Print_Board();
	void Add_First_Cord();
	bool NextTryOrBackTrack(int *i_ptr, int *j_ptr);
	void Solve();
	void SolveOld();
	void Help_Solve(int i, int j);
	bool Check_Conflicts(int p, int i, int j);
	int get_number_of_solutions(void);
};

Sudoku Game;

void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}


Sudoku::Sudoku()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
		board[i][j] = 0;
		permanent[i][j] = false;
		}

	number_of_solutions = 0;
}

void Sudoku::Print_Board()
{
	cout << endl << "--+------+-------+---------" << endl;

	for (int i = 1; i <= 9; i++)
	{
		cout << "  |";

		for (int j = 1; j <= 9; j++)
		{
			if (permanent[i][j] == true)
			{
				setcolor(12);
				cout << board[i][j] << " ";
				setcolor(7);
			}
			else cout << board[i][j] << " ";
			if (j % 3 == 0) cout << "| ";
		}
		cout << endl;
		if (i % 3 == 0) cout << "--+------+-------+---------" << endl;

	}
}

void Sudoku::Add_First_Cord()
{
	board[1][1] = 5; permanent[1][1] = true;
	board[1][2] = 3; permanent[1][2] = true;
	board[1][5] = 7; permanent[1][5] = true;
	board[2][1] = 6; permanent[2][1] = true;
	board[2][4] = 1; permanent[2][4] = true;
	board[2][5] = 9; permanent[2][5] = true;
	board[2][6] = 5; permanent[2][6] = true;
	board[3][2] = 9; permanent[3][2] = true;
	board[3][3] = 8; permanent[3][3] = true;
	board[3][8] = 6; permanent[3][8] = true;
	board[4][1] = 8; permanent[4][1] = true;
	board[4][5] = 6; permanent[4][5] = true;
	board[4][9] = 3; permanent[4][9] = true;
	board[5][1] = 4; permanent[5][1] = true;
	board[5][4] = 8; permanent[5][4] = true;
	board[5][6] = 3; permanent[5][6] = true;
	board[5][9] = 1; permanent[5][9] = true;
	board[6][1] = 7; permanent[6][1] = true;
	board[6][5] = 2; permanent[6][5] = true;
	board[6][9] = 6; permanent[6][9] = true;
	board[7][2] = 6; permanent[7][2] = true;
	board[7][7] = 2; permanent[7][7] = true;
	board[7][8] = 8; permanent[7][8] = true;
	board[8][4] = 4; permanent[8][4] = true;
	board[8][5] = 1; permanent[8][5] = true;
	board[8][6] = 9; permanent[8][6] = true;
	board[8][9] = 5; permanent[8][9] = true;
	board[9][5] = 8; permanent[9][5] = true;
	board[9][8] = 7; permanent[9][8] = true;
	board[9][9] = 9; permanent[9][9] = true;
}

bool Sudoku::Check_Conflicts(int p, int i, int j)
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
			board[i + 2][j + 1] == p || board[i + 2][j + 2] == p)return false;
	}

	/*
	000
	*00
	000
	*/
	if ((j == 1 || j == 4 || j == 7) && (i == 2 || i == 5 || i == 8))
	{
		if (board[i - 1][j] == p || board[i + 1][j] == p || board[i - 1][j + 1] == p ||
			board[i][j + 1] == p || board[i + 1][j + 1] == p || board[i + 1][j + 2] == p ||
			board[i][j + 2] == p || board[i + 1][j + 2] == p)return false;
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
			board[i - 2][j + 1] == p || board[i - 2][j + 2] == p)return false;
	}

	/*
	0*0
	000
	000
	*/
	if ((j == 2 || j == 5 || j == 8) && (i == 1 || i == 5 || i == 7))
	{
		if (board[i - 1][j] == p || board[i + 1][j] == p || board[i - 1][j + 1] == p ||
			board[i][j + 1] == p || board[i + 1][j + 1] == p || board[i + 1][j + 2] == p ||
			board[i][j + 2] == p || board[i + 1][j + 2] == p)return false;
	}

	/*
	000
	0*0
	000
	*/
	if ((j == 2 || j == 5 || j == 8) && (i == 2 || i == 5 || i == 8))
	{
		if (board[i - 1][j] == p || board[i - 1][j - 1] == p || board[i - 1][j + 1] == p ||
			board[i][j + 1] == p || board[i][j - 1] == p || board[i + 1][j + 1] == p ||
			board[i][j] == p || board[i + 1][j - 1] == p)return false;
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
		if (board[i][j - 1] == p || board[i][j - 1] == p || board[i - 1][j] == p ||
			board[i - 1][j - 1] == p || board[i - 1][j - 2] == p || board[i - 2][j] == p ||
			board[i - 2][j - 1] == p || board[i - 2][j - 2] == p) return false;
	}

	return true;
}

void Sudoku::Help_Solve(int i, int j)
{
	cout << "Help_Solved:" << i << " " << j << " " << board[i][j] << " " << permanent[i][j] << endl;

	if (j <= 0)
	{
		i = i - 1;
		j = 9;
	}

	if (permanent[i][j] == true)
	{
		Game.Help_Solve(i, j - 1);
		return;
	}

	for (int p = 1; p <= 9; p++)
		if (Game.Check_Conflicts(p, i, j))
		{
			board[i][j] = p;
			return;
		}

	board[i][j] = 0;
	Game.Help_Solve(i, j - 1);
	return;
}

void Sudoku::SolveOld()
{
	cout << "First pass" << endl;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (board[i][j] == 0 && permanent[i][j] == 0)
			{
				Game.Help_Solve(i, j);
			}
		}
	}

	cout << "Second pass" << endl;

	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (board[i][j] == 0) Game.Help_Solve(i, j);

}


bool Sudoku::NextTryOrBackTrack(int *i_ptr, int *j_ptr)
{
	int p;

	cout << "NextTryOrBackTrack Entry :" << *i_ptr << " " << *j_ptr << " " << board[*i_ptr][*j_ptr] << " " << permanent[*i_ptr][*j_ptr] << endl;

	if (permanent[*i_ptr][*j_ptr] == true)
	{
		cout << "NextTryOrBackTrack Exit 1:" << *i_ptr << " " << *j_ptr << " " << board[*i_ptr][*j_ptr] << " " << permanent[*i_ptr][*j_ptr] << endl;
		return false;
	}

	p = board[*i_ptr][*j_ptr];
	p++;

	while (p <= 9)
	{
		if (Game.Check_Conflicts(p, *i_ptr, *j_ptr))
		{
			board[*i_ptr][*j_ptr] = p;
			cout << "NextTryOrBackTrack Exit 2:" << *i_ptr << " " << *j_ptr << " " << board[*i_ptr][*j_ptr] << " " << permanent[*i_ptr][*j_ptr] << endl;
			return false;
		}
		p++;
	}

	board[*i_ptr][*j_ptr] = 0;
	cout << "NextTryOrBackTrack Exit 3:" << *i_ptr << " " << *j_ptr << " " << board[*i_ptr][*j_ptr] << " " << permanent[*i_ptr][*j_ptr] << endl;
	return true;
}

void Sudoku::Solve()
{
	int i = 1, j = 1;
	bool backtrack;

	while (true)
	{
		while (i <= 9)
		{
			while (j <= 9)
			{
				backtrack = Game.NextTryOrBackTrack(&i, &j);
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
	}
}

int Sudoku::get_number_of_solutions(void)
{
	return number_of_solutions;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Game.Add_First_Cord();
	Game.Print_Board();
	Game.Solve();

	if (Game.get_number_of_solutions() == 0)
	{
		cout << "No Solutions" << endl;
	}
	else if (Game.get_number_of_solutions() == 1)
	{
		cout << "One unique solution!" << endl;
	}
	else
	{
		cout << "Too many solutions" << endl;
	}
//	Game.Print_Board();

//	system("pause");
	return 0;
}

