#include <stdlib.h>
#include <iostream>

using namespace std;

//Global Declarations
char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

int choice, row, column;
char turn = 'X';

bool draw = false;

void printBoard() {
    //Prints a game board with each space set to an index on the matrices
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0]<<"  |  " << board[0][1] << "  |  " << board[0][2] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] <<"  |  " << board[1][1] << "  |  " << board[1][2] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] <<"  |  " << board[2][1] << "  |  " << board[2][2] << " " << endl;
    cout << "     |     |     " << endl;

}

//check if the game is over
bool gameState() {
    //Checks for winning rows/columns/diagonals
    for(int i = 0; i < 3; i++) 
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return false;

    //Checks if there are open spaces within the board
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' || board[i][j] != '0') 
                return true;
        }
    

    //No more moves can be made & No winner
    draw = true;
    return false;
    
}

//make a selection
//change the board
void playerTurn() {
    if (turn == 'X') {
        cout << "Player 1 Turn: " << endl;
    } else  {
        cout << "Player 2 Turn: " << endl;
    }

    cin >> choice;

    switch(choice) {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){

        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
  
        board[row][column] = 'O';
        turn = 'X';
    }else {
        cout << "Spot taken. Try again.";
        playerTurn();
    }
    
}

int main() {
    cout << "TIC TAC TOE" << endl;
    cout << "Player 1: X    Player 2: O" << endl;

    //Loop through game
    while(gameState()) {
        printBoard();
        playerTurn();
        gameState();
    };

    printBoard();
    //Player and turn is swapped since turn is reassigned after choice is made
    if(turn == 'X' && draw == false){
        cout << "Congratulations!\nPlayer 2 has won the game!";
    }
    else if(turn == 'O' && draw == false){
        cout << "Congratulations!\nPlayer 1 has won the game!";
    }
    else

    cout << "Tie Game. No winners.";
}