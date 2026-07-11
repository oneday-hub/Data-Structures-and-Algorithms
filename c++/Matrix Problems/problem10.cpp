/*
leetcode 1219. Path with Maximum Gold

https://leetcode.com/problems/path-with-maximum-gold/description/?envType=problem-list-v2&envId=matrix


In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
*/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(vector<vector<int>>& grid, int i, int j) {
    int rows = grid.size();
    int cols = grid[0].size();

    // boundary + invalid cell
    if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0)
        return 0;

    int gold = grid[i][j];

    // mark visited
    grid[i][j] = 0;

    int maxGold = 0;

    // explore all 4 directions
    for(int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        maxGold = max(maxGold, dfs(grid, ni, nj));
    }

    // backtrack
    grid[i][j] = gold;

    return gold + maxGold;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    // input grid
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    // try starting from every gold cell
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != 0) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}