#include "pch.h"
#include<iostream>
using namespace std;

const int DIM = 3;
char chessboard[DIM][DIM];
//initChessBoard
void initChessBoard(char cb[][DIM])
{
	for (int i = 0; i < DIM; i++)
	{

		for (int j = 0; j < DIM; j++)
		{
			cb[i][j] = 'B';
		}
	}

}

//printChessBoard
void printChessBoard(char cb[][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			cout << cb[i][j] << ' ';

		}
		cout << endl;
	}


}

//putChequer
bool putChequer(char cb[][DIM], int i, int j, char x)
{
	/* if i and j are not out of bound(that is, i and j are in the range of 0 and DIM-1) and cb[i][j] is not occupied(that is, the value of cb[i][j] is ‘B’), set cb[i][j] to be the value of x and return true. Otherwise, return false.*/
	if ((i >= 0 && i < DIM) && (j >= 0 && j < DIM) && (cb[i][j] == 'B'))
	{
		cb[i][j] = x;
		return true;
	}
	else
	{
		return false;
	}
}
//judge the state of the game. The player has put x in the position (row, col). 
bool state(char cb[][DIM], int row, int col, char x)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

	for (int i = 0; i < DIM; ++i)
	{
		// Complete this part in the following:
		// if the element in position (row, i) is x, count1 is increased by 1.

		// if the element in position (i, col) is x, count2 is increased by 1.

		/* if x is in the main diagonal, and the element in position (i, i) is x, count3 is increased by 1.*/

		/* if x is in the opposite diagonal, and the element in position (i, DIM-1-i) is x, count4 is increased by 1.*/
		if (cb[row][i] == x)
		{
			count1++;
		}
		if (cb[i][col] == x)
		{
			count2++;
		}
		if (cb[i][i] == x)
		{
			count3++;
		}
		if (cb[i][DIM - 1 - i] == x)
		{
			count4++;
		}
	}
	return (count1 == DIM || count2 == DIM || count3 == DIM || count4 == DIM);
}

int main()
{
	int row, col;
	int blanks = DIM * DIM;
	initChessBoard(chessboard);
	printChessBoard(chessboard);
	char cur = 'O';

	cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
	cin >> row >> col;

	while (row != -1 && col != -1)
	{
		if (!putChequer(chessboard, row, col, cur))
		{
			cout << "Invalid move" << endl;
			printChessBoard(chessboard);
		}
		else
		{
			--blanks;
			printChessBoard(chessboard);
			if (state(chessboard, row, col, cur))
			{
				cout << cur << " Wins" << endl;
				return 0;
			};
			if (blanks == 0)
			{
				cout << "Ties" << endl;
				return 0;
			}
			if (cur == 'X')
				cur = 'O';
			else cur = 'X';
		}
		cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
		cin >> row >> col;
	}
}