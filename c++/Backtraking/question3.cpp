// question : so here we printing the path means the total no of ways 
//            in 3*3 maze 

#include<iostream>
using namespace std;

// Modified to return the count of paths
int printPath(int sr, int sc, int er, int ec, string s){
    if(sr > er || sc > ec) return 0;  // Out of bounds
    
    if(sr == er && sc == ec){
        cout << s << endl;  // Valid path found
        return 1;
    }

    // Move right and down, and count total paths
    int rightPaths = printPath(sr, sc + 1, er, ec, s + "R");
    int downPaths = printPath(sr + 1, sc, er, ec, s + "D");

    return rightPaths + downPaths;
}

int main(){
    int rows = 3; 
    int cols = 3;

    // Call printPath starting from (1,1) to (rows,cols)
    int count = printPath(1, 1, rows, cols, "");

    cout << "Number of ways: " << count << endl;
    return 0;
}
