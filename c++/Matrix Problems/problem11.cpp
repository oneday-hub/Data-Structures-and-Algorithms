/*
1254. Number of Closed Islands
https://leetcode.com/problems/number-of-closed-islands/description/?envType=problem-list-v2&envId=matrix

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and 
a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: Islands in gray are closed because they are completely surrounded by water (group of 1s).
*/
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &grid, int i , int j){
    int rows  = grid.size();
    int cols = grid[0].size();

    if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 1){
        return;
    }

    // mark visited
    grid[i][j] = 1;

    for(int k = 0; k < 4; k++){
        int ni = i + dx[k]; 
        int nj = j + dy[k];

        dfs(grid, ni, nj);
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    // 🔥 Step 1: remove boundary-connected 0s
    for(int i = 0; i < m; i++){
        if(grid[i][0] == 0) dfs(grid, i, 0);
        if(grid[i][n-1] == 0) dfs(grid, i, n-1);
    }

    for(int j = 0; j < n; j++){
        if(grid[0][j] == 0) dfs(grid, 0, j);
        if(grid[m-1][j] == 0) dfs(grid, m-1, j);
    }

    // 🔥 Step 2: count closed islands
    int closedisland = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                closedisland++;
                dfs(grid, i, j);
            }
        }
    }

    cout << closedisland << endl;

    return 0;
}