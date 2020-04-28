#include <iostream>

using namespace std;


void greetAndInstruct()
{
	int counter = 1;
	char charInput;
	cout<<"Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer"<<endl
	<< "The board is numbered from 1 to 27 as per the following"<<endl;
		for (int i = 0; i < 5; i ++)
		{
			if (i % 2 != 0)
				cout<<"----------"<<"\t\t"<<"-------------"<<"\t\t"<<"-------------"<<endl;
			else
			{
				for (int j = 0; j < 3; j ++)
				{
					if (j == 0 )
						cout << counter;
					else
						cout << " | " << counter;
					counter ++;
				}
				cout << "\t\t";
				for (int k = 0; k < 3; k ++)
				{
					if (k == 0)
						cout << counter+6;
					else
						cout << " | "<< counter+6+k;
				}
				cout << "\t\t";
				for (int m = 0; m < 3; m ++)
				{
					if (m == 0)
						cout << counter + 15;
					else
						cout << " | "<< counter + 15 + m;
				}
				cout << endl;
			}
		}
	cout<< "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X."
	<<"Computer's move is marked with O."<<endl;

START:    cout<<"Start?(y/n):"<<endl;
	cin >> charInput;
	if (charInput == 'n' | charInput == 'N')
	{
		cout<<"See you next time!"<<endl;
		exit(1);
	}
	else if(charInput == 'y'  | charInput == 'Y')
		cout<<"the game starts"<<endl;
	else
		{
		cout << "Invalid Arguments\n";
		goto START;
		}
}

void displayBoard(char board[])
{
	int counter = 1;
	for (int i = 0; i < 5; i ++)
		{
			if (i % 2 != 0)
				cout<<"----------"<<"\t\t"<<"----------"<<"\t\t"<<"----------"<<endl;
			else
			{
				for (int j = 0; j < 3; j ++)
				{
					if (j == 0 && !board[counter-1])
						cout << " ";
					else if(j == 0 && board[counter -1])
						cout << board[counter-1];
					else if(j != 0 && !board[counter -1])
						cout << " | " << " ";
					else
						cout << " | " << board[counter -1];
					counter ++;
				}
				cout << "\t\t";
				for (int k = 0; k < 3; k ++)
				{
					if (k == 0 && !board[counter+5+k])
						cout << " ";
					else if(k == 0 && board[counter+5+k])
						cout << board[counter+5+k];
					else if(k != 0 && !board[counter+5+k])
						cout << " | " << " ";
					else
						cout << " | " << board[counter+5+k];
				}
				cout << "\t\t";
				for (int m = 0; m < 3; m ++)
				{
					if (m == 0 && !board[counter+14+m])
						cout << "  ";
					else if(m == 0 && board[counter+14+m])
						cout << board[counter+14+m];
					else if(m != 0 && !board[counter+14+m])
						cout << " | " << " ";
					else
						cout << " | " << board[counter+14+m];
				}
				cout << endl;
			}
		}
}

bool checkIfLegal(int cellNbre, char board[])
{
	return cellNbre > 0 && cellNbre < 27 && board[cellNbre-1] != 'O' && board[cellNbre-1] != 'X';
}


bool isFirstLine(int num)
{
	int firstLine[9] = {0,1,2,9,10,11,18,19,20};
	for (int i : firstLine)
	{
		if (num == i)
			return true;
	}
	return false;
}

bool isSecondLine(int num)
{
	int secondLine[9] = {3,4,5,12,13,14,21,22,23};
	for (int i : secondLine)
	{
		if (num == i)
			return true;
	}
	return false;
}

bool isLastLine(int num)
{
	int lastLine[9] = {6,7,8,15,16,17,24,25,26};
	for (int i : lastLine)
	{
		if (num == i)
			return true;
	}
	return false;
}

bool isFirstColumn(int num)
{
	int firstColumn[9] = {0,3,6,9,12,15,19,22,25};
	for (int i : firstColumn)
	{
		if (num == i)
			return true;
	}
	return false;
}

bool isSecondColumn(int num)
{
	int secondColumn[9] = {1,4,7,10,13,16,19,22,25};
	for (int i : secondColumn)
	{
		if (num == i)
			return true;
	}
	return false;
}


bool isLastColumn(int num)
{
	int lastColumn[9] = {2,5,8,11,14,17,20,23,26};
	for (int i : lastColumn)
	{
		if (num == i)
			return true;
	}
	return false;
}

bool isFirstMatrix(int num)
{
	return num >= 0 && num <9;
}



bool checkWinner(char board[])
{
	int count = 0;
	for(int i =0; i< 26; i++)
	{
		if (board[i]){
			count ++;
		if (isFirstLine(i) )
		{
			if ((board[i] == board[i+3]) && (board[i] == board[i+6]))
			{
				return true;
			}
		}
		if (isFirstColumn(i) )
		{
			if ((board[i] == board[i+1]) && (board[i] == board[i+2]))
			{
				return true;
			}
		}
		if (isFirstMatrix(i) )
		{
			if ((board[i] == board[i+9]) && (board[i] == board[i+18]))
				return true;
		}
		if (i == 0)
		{
			if ((board[i] == board[i+13]) && (board[i] == board[i+26]))
			{
				return true;
			}
		}
		if (i == 2)
		{
			if ((board[i] == board[i+11]) && (board[i] ==board[i+22]))
			{
				return true;
			}
		}
		if (isSecondLine(i) )
		{
			if ((board[i-3] == board[i]) && (board[i+3] == board[i]))
			{
				return true;
			}
		}
		if (isLastLine(i) )
		{
			if ((board[i-3] == board[i]) && (board[i-6] == board[i]))
			{
				return true;
			}
		}
		if (isSecondColumn(i) )
		{
			if ((board[i-1] == board[i]) && (board[i+1] == board[i]))
			{
				return true;
			}
		}
		if (isLastColumn(i) )
		{
			if ((board[i-2] == board[i]) && (board[i-1] == board[i]))
			{
				return true;
			}
		}
		if ((i == 0 || i == 9 || i == 18) )
		{
			if ((board[i+4] == board[i]) && board[i+8] == board[i])
			{
				return true;
			}
		}
		if ((i == 2 || i == 11 || i == 20) )
		{
			if ((board[i+2] == board[i]) && board[i+4] == board[i])
			{
				return true;
			}
		}
		if ((i == 4 || i == 13 || i == 22) )
		{
			if ((board[i - 4] == board[i]) &&(board[i+4] == board[i]))
			{
				return true;
			}
			else if ((board[i-2] == board[i]) && (board[i+2] == board[i]))
			{
				return true;
			}
		}
		if ((i == 6 || i == 15 || i == 24) )
		{
			if ((board[i-2] == board[i]) && (board[i-4] == board[i]))
				return true;
		}
		if ((i == 8 || i == 17 || i == 26) )
		{
			if ((board[i-4] == board[i]) && (board[i-8] == board[i]))
			{
				return true;
			}
		}
	}
	}
    if (count == 26) 
	{
        cout << "tie!" << endl;
		exit(1);
    }
	return false;
}



void computerMove(char board[])
{
	int counter = 0;
	bool seen = false;
	for(int i = 1; i<27; i++)
	{
		counter ++;
		if (checkIfLegal(i,board))
		{
			board[i-1] = 'O';
			if(checkWinner(board))
			{
				return;
			}
			board[i-1] = 'X';
			if(checkWinner(board))
			{
				board[i-1] = 'O';
				return;
			}
			board[i-1] = '\0';
		}
		if(counter == 26)
		{
			for (int j = 1; j<27; j++)
			{
				if (board[j-1] && checkIfLegal(j+1,board) && seen == false)
				{
					board[j] = 'O';
					seen = true;
					return;
				}
				seen = false;
			}
		}
	}
}

