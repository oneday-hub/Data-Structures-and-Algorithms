// topic 3 : more basic problems : 

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    // 1. Scalar multiplication : 
    int rows, cols; 
    cout << "Enter the no of rows : ";
    cin >> rows; 

    cout << "Enter the no of columns : ";
    cin >> cols; 

    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Enter the matrix 1 : ";
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cin >> matrix[i][j];
        }
    }

    int k;
    cout << "Enter the scalar k : ";
    cin >> k; 
    vector<vector<int>> ans(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ans[i][j] = k * matrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}