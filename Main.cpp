#include "stdafx.h"// So we can compile it on Visual Studio! do not remove
#include <iostream>
#include <windows.h> 
using namespace std;




class Table
{
private:
	char data[9];

public:
	Table()//initializes board
	{
		for (int i = 0; i < 9; ++i)
		{
			data[i] = ' ';
		}
	}

	void Set(int row, int column, char letter)//sets an letter on board
	{
		data[row * 3 + column] = letter;
	}

	char Get(int row, int column)//gets a letter on board
	{
		return data[row * 3 + column];
	}
	
	
	

	void Draw()//draws board
	{
		cout << "  1 2 3" << endl;
		for (int r = 0; r < 3; ++r)
		{
			cout << endl;
			cout << " _______" << endl;
			cout << r + 1;
			for (int c = 0; c < 3; ++c)
			{
				cout << "|" << Get(r, c);
			}
			cout << "|" << endl;
		}
		cout << " _______" << endl;
	}
	
	

	bool CheckForWin()
	{
		//check for 3 in a row win

		for (int r = 0; r < 3; ++r)//for each row
		{
			if (Get(r, 0) != ' ' && Get(r, 0) == Get(r, 1) && Get(r, 1) == Get(r, 2))//if all 3 columns are the same
			{
				Draw();

				cout << endl;

				if (Get(r, 0) == 'x')
				{
					cout << "player 1 wins!" << endl;
				}
				else
				{
					cout << "player 2 wins!" << endl;
				}

				return true;
			}
		}

		//check for 3 in a column
		//...

		//Check for 3 diagonal
		//...

		return false;
	}
};


int main()
{
	SetConsoleTitle(TEXT(" Quantum Works Tic Tac Toe "));// console name! do not remove
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\n\t\t\t  ______________________";
	cout << "\n\t\t\t | \t\t\t|";
	cout << "\n\n\t\t | Quantum Works\t | ";
	cout << "\n\t\t\t | \t\t\t|";
	cout << "\n\t\t\t | All Rights Reserved\t|";
	cout << "\n\t\t\t |______________________|";
	cout << "\n\t\t\t\t";

	system("color 90");
	Sleep(2000);

	system("cls");
	//board(); //This shuld be the map lol
	Table table;

	int row, column;

	while (true)
	{
		//player 1

		table.Draw();

		cout << endl << "player 1's turn( x )" << endl;

	a:

		cout << "enter a row & column: " << endl;

		cin >> row >> column;

		if (table.Get(row - 1, column - 1) != ' ')
		{
			cout << "invalid pick, please choose again." << endl;
			goto a;
		}
		else
		{
			table.Set(row - 1, column - 1, 'x');
		}

		if (table.CheckForWin())
		{
			break;
		}

		//player 2

		table.Draw();

		cout << endl << "player 2's turn( o )" << endl;

	b:

		cout << "enter a row & column: " << endl;

		cin >> row >> column;

		if (table.Get(row - 1, column - 1) != ' ')
		{
			cout << "invalid pick, please choose again." << endl;
			goto b;
		}
		else
		{
			table.Set(row - 1, column - 1, 'o');
		}

		if (table.CheckForWin())
		{
			break;
		}
	}

	cout << endl;

	Sleep(2000);
	system("pause");

}
/*
void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
*/

