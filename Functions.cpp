#include "Functions.h"

void runGame()
{
    char w[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    initBoard(w);

    char piece = 'X';
    int x_cord;
    int y_cord;
    
	cout << "Enter coordinate for " << piece << ". Input should be X Y\n";
	cin >> x_cord;
    cin.ignore();
    cin >> y_cord;
	placeAPiece(x_cord, y_cord, piece, w);
	
    while (!checkForWinner(piece, w)){
        if (checkForDraw(w)){
            cout << "Draw\n";
            break;
        }
        if (piece == 'X'){
			piece = 'O';
		}
		else if (piece == 'O'){
			piece = 'X';
		}
        cout << "Enter coordinate for " << piece << ". Input should be X Y\n";
        cin >> x_cord >> y_cord;
        placeAPiece(x_cord, y_cord, piece, w);
    }

    if (checkForWinner(piece, w)){
        cout << piece << " Won\n";
    }
    
    char again;
    cout << "Do you want to play again?\n";
    cin >> again;
    if (again == 'N' or again == 'n'){
        cout << "Done\n";
        exit;
    }
    else{
        runGame();
    }
}

void initBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}

void placeAPiece(int x, int y, char piece, char board[3][3])
{
    if (board[x][y] == '-'){
        board[x][y] = piece;
        displayBoard(board);
    }
    else{
        cout << "Invalid move\n";
    }
}

bool checkForWinner(char piece, char board[3][3])
{
    for (int i = 0; i < 3; i++){
        if ((board[i][0] == piece && board[i][1] == piece && board[i][2] == piece) or (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece)){
            return true;
        }
    }
    
    if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece or board[0][2] == piece && board[1][1] == piece && board[2][0] == piece){
        return true;
    }
    
    return false;
}

bool checkForDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                return false;
            }
        }
    }
    return true;
}


void displayBoard(char board[3][3])
{
    cout << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << '\n';
    cout << "-----" << '\n';
    cout << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << '\n';
    cout << "-----" << '\n';
    cout << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << '\n';
}