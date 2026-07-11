
// traversals in matrix : 

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

    // 1. Row - wise Traversals : 
    cout << "Row - wise Traversal : " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 2. Colums-wise Traversals
    cout << "Cols - wise Traversal : " << endl;
    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows; i++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 3. Reverse Row - wise Traversal
    cout << "Reverse Row - wise Traversal : " << endl;
    for(int i = 0; i < rows ; i++){
        for(int j = cols - 1; j >= 0; j--){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 4. Reverse Column - wise Traversal
    cout << "Reverse Column - wise Traversal : " << endl;

    for(int j = 0; j < cols; j++){
        for(int i = rows - 1; i >= 0; i--){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 5. transpose Traversal
    cout << "Transpose Traversal : " << endl;
    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows; i++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}