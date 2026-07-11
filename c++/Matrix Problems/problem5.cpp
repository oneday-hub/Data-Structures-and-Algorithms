// topic 2 : Advanced : True Diagonal Traversal 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows ;
    cout << "Enter the rows : ";
    cin >> rows;

    int cols; 
    cout << "Enter the cols : ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i<rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    //Simple Diagonal Traversal (Group by i+j)
    //We iterate diagonals using d = i + j.

    cout << "Simple Diagonal Traversal (Group by i+j) : " << endl;
    for(int d = 0; d <= rows + cols - 2; d++){
        for(int i = 0; i<rows; i++){
            int j = d - i;
            
            if(j >= 0 && j < cols){
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;

}

// the output : 

/*
Enter the rows : 3
Enter the cols : 3
1 2 3
4 5 6
7 8 9
Simple Diagonal Traversal (Group by i+j) : 
1 
2 4 
3 5 7 
6 8 
9 
*/