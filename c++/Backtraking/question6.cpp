// rat in maze - 3 with deadblocks in 2 directions


#include <iostream>
#include <vector>
using namespace std;

// Modified to return the count of paths
int printPath(int sr, int sc, int er, int ec, string s, vector<vector<int>> &maze) {
    // Check if out of bounds or path is blocked
    if (sr > er || sc > ec || sr < 0 || sc < 0 || maze[sr][sc] == 0)
        return 0;

    // 3 coditions here : 
    // condition 1 : if(sr>er||sc>ec) return;
    // condition 2 : if(sr<0||sc<0) return;
    // condition 3 : if(maze[sr][sc]==0) return;


    // Destination reached
    if (sr == er && sc == ec) {
        cout << s << endl;
        return 1;
    }

    // Mark as visited (optional for blocked cells or if you don't want to revisit)
    maze[sr][sc] = 0;

    // Move right and down (can add left/up for more directions)
    int rightPaths = printPath(sr, sc + 1, er, ec, s + "R", maze);
    int downPaths = printPath(sr + 1, sc, er, ec, s + "D", maze);
    
    // Backtrack
    maze[sr][sc] = 1;

    return rightPaths + downPaths ;
}

int main() {
    int rows = 4;
    int cols = 6;

    vector<vector<int>> maze = {
        {1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1, 1}
    };

    int count = printPath(0, 0, rows - 1, cols - 1, "", maze);
    cout << "Number of ways: " << count << endl;

    return 0;
}
