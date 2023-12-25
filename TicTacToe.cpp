#include <iostream>
#include<conio.h>

using namespace std;
void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool isBoardFull(char board[3][3]);
void play();
void instructions();

int main() {
    int op;
    system("cls");
    system("color F4");
    cout << "Welcome to Tic Tac Toe!" << endl;
    while (true)
    {
      cout<<" 1. Play "<<endl;
      cout<<" 2. Instructions"<<endl;
      cout<<" 3. Exit"<<endl;
    cout << "Choose an option: ";
    cin >> op;

    if (op == 1) {
        play();
    } else if (op == 2) {
        instructions();
    } else if (op == 3) {
        exit(0);
    }
    }
    return 0;
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void play() {
    system("cls");
    char board[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };
    char currentPlayer = 'X';
    while (true) {
            system("cls");

        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            cout<<"Press any key to continue";
            getch();
            system("cls");
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            cout<<"Press any key to continue";
            getch();
            system("cls");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void instructions() {
    cout << "This is a simple Tic Tac Toe game. Players take turns entering their moves, "
         << "and the first player to get three in a row wins. Have fun!" << endl;
}
