#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------CHESS BOARD--------------------------" << endl;
}

bool isSafe(vector<vector<char>>& board, int row, int col) {
    int n = board.size();
    // Check in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'q') return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'q') return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'q') return false;
    }

    return true;
}

void Nqueens(vector<vector<char>>& board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'q';
            Nqueens(board, row + 1);
            board[row][j] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n x n): ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    Nqueens(board, 0);

    return 0;
}
