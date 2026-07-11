// problem 9  : leetcode 695 : max area of island 
#include <bits/stdc++.h>
using namespace std;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

int dfs(vector<vector<int>> &grid, int i, int j){

    int r = grid.size();
    int c = grid[0].size();

    if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0){
        return 0;
    }
    grid[i][j] = 0;
    int area = 1; 

    for(int k = 0; k < 4; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];

        area += dfs(grid, ni, nj);
    }
    return area;
}
int maxAreaofIsland(vector<vector<int>> &grid){
    int r = grid.size();
    int c = grid[0].size();

    int maxarea = 0;

    for(int i = 0; i<r; i++){
        for(int j = 0; j < c ; j++){

            if(grid[i][j] == 1){
                
                int area = dfs(grid, i, j);
                maxarea = max(maxarea, area);
            }
        }
    }

    return maxarea;
}

int main() {
    int n, m; 
    cout << "Enter the row and col : ";
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j < m ;j++){
            cin >> grid[i][j];
        }
    }
    cout << "Max Area : " << maxAreaofIsland(grid) ; 
    
    return 0;
}