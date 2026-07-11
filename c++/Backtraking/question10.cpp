// same problem : N queen 
// also give the  number of distinct solutions

#include<iostream>
#include<vector>
using namespace std;

int count = 0;  // To store total number of valid solutions

bool isSafe(vector<vector<char>>& board, int row, int col) {
    int n = board.size();

    // Check the row
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') return false;
    }

    // Check the column
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check north-east (NE)
    int i1 = row, j1 = col;
    while (i1 >= 0 && j1 < n) {
        if (board[i1][j1] == 'Q') return false;
        i1--;
        j1++;
    }

    // Check south-east (SE)
    int i2 = row, j2 = col;
    while (i2 < n && j2 < n) {
        if (board[i2][j2] == 'Q') return false;
        i2++;
        j2++;
    }

    // Check south-west (SW)
    int i3 = row, j3 = col;
    while (i3 < n && j3 >= 0) {
        if (board[i3][j3] == 'Q') return false;
        i3++;
        j3--;
    }

    // Check north-west (NW)
    int i4 = row, j4 = col;
    while (i4 >= 0 && j4 >= 0) {
        if (board[i4][j4] == 'Q') return false;
        i4--;
        j4--;
    }

    return true;
}

void nQueen(vector<vector<char>>& board, int row) {
    int n = board.size();

    if (row == n) {
        // Print one valid configuration
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;

        count++; // Increment count for each valid configuration
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';
            nQueen(board, row + 1);
            board[row][j] = 'x'; // Backtracking
        }
    }
}

int main() {
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n, 'x'));

    nQueen(board, 0);

    cout << "Total solutions: " << count << endl;

    return 0;
}
