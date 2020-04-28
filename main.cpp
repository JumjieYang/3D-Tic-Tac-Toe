#include <iostream>
#include "functions.cpp"
using namespace std;

int main(int argc, char** argv)
{
    char board[27];
    int inputIndex;
    greetAndInstruct();
    while (!checkWinner(board))
    {
            displayBoard(board);
FLAG:            cout<<"Please input the number of cell you want to place from 1 to 27: ";
            cin >> inputIndex;
            cout<<endl;
            if(!checkIfLegal(inputIndex,board))
                goto FLAG;
            board[inputIndex-1] ='X';
            cout<<"----------------------------------------------------------------"<<endl;

            displayBoard(board);

            if(checkWinner(board))
            {
                cout<< "Player Win"<<endl;
                exit(0);
            }
            computerMove(board);
            cout<<"----------------------------------------------------------------"<<endl;
            displayBoard(board);
            cout<<"----------------------------------------------------------------"<<endl;

            if(checkWinner(board))
            {
                cout<< "Computer Win"<<endl;
                exit(0);
            }
            
    }
    return 0;
    
}