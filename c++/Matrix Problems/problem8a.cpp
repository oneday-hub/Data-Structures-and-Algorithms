// topic 8 : dfs on matrix : 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();

        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            dfs(grid, ni, nj);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        int islands = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};