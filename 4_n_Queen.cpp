#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Check if there is a queen in the same column or diagonals
        if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
            return false;
        }
    }
    return true;
}

bool solveNQueensBacktracking(vector<int>& board, int row, int n) {
    if (row == n)   return true;

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            
            if (solveNQueensBacktracking(board, row + 1, n)) {
                return true;
            }
        }
    }
    return false;
}

bool solveNQueensBranchBound(vector<int>& board, int row, int n) {
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueensBranchBound(board, row + 1, n)) {
                return true;
            }
            board[row] = -1;
        }
    }
    return false;
}

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n x n): ";
    cin >> n;

    vector<int> board(n, -1);

    // Solve using Backtracking
    cout << "Solution using Backtracking:\n";
    if (solveNQueensBacktracking(board, 0, n)) {
        printBoard(board);
    } else {
        cout << "No solution exists!\n";
    }

    // Solve using Branch and Bound
    cout << "\nSolution using Branch and Bound:\n";
    if (solveNQueensBranchBound(board, 0, n)) {
        printBoard(board);
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
