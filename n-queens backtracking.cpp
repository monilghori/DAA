#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    /*
     * Returns true if placing a queen at row, col in the board is safe.
     * A placement is considered safe if no other queen can attack it.
     */
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false; // another queen is already in the same column
        }
        if (col-row+i >= 0 && board[i][col-row+i] == 1) {
            return false; // another queen is already in the same diagonal
        }
        if (col+row-i < n && board[i][col+row-i] == 1) {
            return false; // another queen is already in the same diagonal
        }
    }
    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int n, vector<vector<int>>& solutions) {
    /*
     * Solves the n-queens problem by placing a queen in each row of the board.
     * Returns all possible solutions as a vector of 2D arrays.
     */
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueens(board, row+1, n, solutions);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> solutions;
    solveNQueens(board, 0, n, solutions);
    int count = 1;
    for (vector<vector<int>>& solution : solutions) {
        cout << "Solution #" << count << ":" << endl;
        for (vector<int>& row : solution) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
        count++;
    }
    return 0;
}
