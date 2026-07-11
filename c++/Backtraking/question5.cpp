// question : rat in the maze - 4 direction 
// also the explaination of backtracking :
#include <iostream>
#include <vector>
using namespace std;

int fourDirectionPath(int sr, int sc, int er, int ec, string s, vector<vector<bool>>& visited) {
    // Check boundaries
    if (sr < 0 || sc < 0 || sr > er || sc > ec) return 0;

    // Check if cell is already visited 
    if (visited[sr][sc] == true) return 0;

    // if not visited : 
    // Destination reached
    if (sr == er && sc == ec) {
        cout << s << endl;
        return 1;
    }

    // Mark current cell as visited
    visited[sr][sc] = true;

    // Explore all 4 directions
    int right = fourDirectionPath(sr, sc + 1, er, ec, s + "R", visited);
    int down  = fourDirectionPath(sr + 1, sc, er, ec, s + "D", visited);
    int left  = fourDirectionPath(sr, sc - 1, er, ec, s + "L", visited);
    int up    = fourDirectionPath(sr - 1, sc, er, ec, s + "U", visited);

    // Backtrack (unmark cell)
    visited[sr][sc] = false;
    /*
    This line is crucial in backtracking algorithms. It unmarks the current cell (sr, sc) as visited 
    so that it can be used again in other paths. Here's why:
    
When you visit a cell, you set visited[sr][sc] = true to prevent revisiting it during the current recursive path.

After all recursive calls from that cell are done (exploring right, down, left, up), 
you backtrack — and as part of backtracking, you reset the visited status: visited[sr][sc] = false.

This allows other recursive paths to include this cell as part of a different route.
Without this line, you'd mark the cell as visited but never allow it to be used again, 
which would lead to incomplete exploration of all valid paths.
*/
    return right + down + left + up;
}

int main() {
    int rows = 3, cols = 3;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int totalPaths = fourDirectionPath(0, 0, rows - 1, cols - 1, "", visited);
    cout << "Total valid paths: " << totalPaths << endl;

    return 0;
}
