#include <iostream>
using namespace std;

void printBoard(char board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------CHESS BOARD--------------------------" << endl;
}

bool isSafe(char board[4][4], int row, int col) {
    // vertical up
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'q') return false;
    }

    // diagonal left up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'q') return false;
    }

    // diagonal right up
    for (int i = row - 1, j = col + 1; i >= 0 && j < 4; i--, j++) {
        if (board[i][j] == 'q') return false;
    }

    return true;
}

void Nqueens(char board[4][4], int row) {
    if (row == 4) {
        printBoard(board);
        return;
    }
    for (int j = 0; j < 4; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'q';
            Nqueens(board, row + 1);
            board[row][j] = '.';
        }
    }
}

int main() {
    char board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = '.';
        }
    }
    Nqueens(board, 0);

    return 0;
}
