// problem : N queen problem 
#include<iostream>
#include<vector>
using namespace std;

// bool isSafe(vector<vector<char>>& board, int row, int col){

//     //check the row
//     int n = board.size();
//     for(int j = 0; j<n; j++){
//         if(board[row][j] == 'Q') return false;
//     }
//     //check the col
//     int n = board.size();
//     for(int i = 0; i<n; i++){
//         if(board[i][col] == 'Q') return false;
//     }
//     // check north east (NE)
//     int i = row ; 
//     int j = col ; 
//     while(i>=0 && j<n){
//         if(board[i][j] == 'Q') return false;
//         i--;
//         j++;
//     }
//     // check south east (SE)
//     int i = row ; 
//     int j = col ; 
//     while(i<n && j<n){
//         if(board[i][j] == 'Q') return false;
//         i++;
//         j++;
//     }
//     // check south west (SW)
//     int i = row ; 
//     int j = col ; 
//     while(i<n && j>=0){
//         if(board[i][j] == 'Q') return false;
//         i++;
//         j--;
//     }
//     // check north west (SW)
//     int i = row ; 
//     int j = col ; 
//     while(i>=0 && j>=0){
//         if(board[i][j] == 'Q') return false;
//         i--;
//         j--;
//     }
//     return true ;

// }

// You're getting these "redeclaration" errors because you're declaring the 
// same variables int i, int j, and int n multiple times within the same scope of your isSafe function. 
// C++ doesn't allow that.



bool isSafe(vector<vector<char>>& board, int row, int col){
    int n = board.size();

    // Check the row
    for(int j = 0; j < n; j++){
        if(board[row][j] == 'Q') return false;
    }

    // Check the column
    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q') return false;
    }

    // Check north-east (NE)
    int i1 = row, j1 = col;
    while(i1 >= 0 && j1 < n){
        if(board[i1][j1] == 'Q') return false;
        i1--;
        j1++;
    }

    // Check south-east (SE)
    int i2 = row, j2 = col;
    while(i2 < n && j2 < n){
        if(board[i2][j2] == 'Q') return false;
        i2++;
        j2++;
    }

    // Check south-west (SW)
    int i3 = row, j3 = col;
    while(i3 < n && j3 >= 0){
        if(board[i3][j3] == 'Q') return false;
        i3++;
        j3--;
    }

    // Check north-west (NW)
    int i4 = row, j4 = col;
    while(i4 >= 0 && j4 >= 0){
        if(board[i4][j4] == 'Q') return false;
        i4--;
        j4--;
    }

    return true;
}

void nQueen(vector<vector<char>>& board, int row){
    int n = board.size();

    if(row == n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        return ;
    }

    for(int j = 0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            nQueen(board,row+1);
            board[row][j] = 'x'; // Backtraking 
        }
    }
}

int  main(){
    int n = 6;
    vector<vector<char>> board(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = 'x';
        }
    }
    
    nQueen (board, 0);
    

    return 0;
}