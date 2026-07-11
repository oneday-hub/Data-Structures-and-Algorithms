// topic 4 : Diagonal Traversals in Matrix : 


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cout << "Enter the size of matrix : ";
    cin >> n; 

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
        
    }
    cout << "Main Diagonal elements : ";
    for(int i = 0; i<n; i++){
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    cout << "secondary Diagonal : ";
    for(int i = 0; i < n; i++){
        cout << matrix[i][n - i - 1] << " ";
    }
    cout << endl;

    cout << "Diagonal sum : ";
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += matrix[i][i]; // main diagonal
        sum += matrix[i][n - i - 1]; // secondary diagonal
    }
    if(n % 2 == 1 ){
        sum -= matrix[n/2][n/2];
    }

    cout << "The sum of both diagonal of matrix : " << sum << endl;

    cout << "Upper Triange of matrix : " << endl;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Lower Triange of matrix : ";
    for(int i = 0; i<n; i++){
        for(int j = 0; j < i; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}