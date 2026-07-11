/*
54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/description/?envType=problem-list-v2&envId=matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    int top = 0; 
    int bottom = r - 1;
    int left = 0;
    int right = c - 1; 

    vector<int> ans;

    while(top <= bottom && left <= right){
        // 1. left -> right
        for(int j = left; j <= right; j++){
            ans.push_back(matrix[top][j]);
        }
        top++;

        // 2. top -> bottom
        for(int i = top; i <= bottom ; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // 3. right -> left
        if(top <= bottom){
            for(int j = right; j >= left ; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        
        // 4. bottom -> top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // input
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    // output
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}