#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the No of rows : ";
    cin >> rows;
    cout << "Enter the No of cols : ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
        
    }
    return 0;
}