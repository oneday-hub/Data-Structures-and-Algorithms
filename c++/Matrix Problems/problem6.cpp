// level 3 : Direction vectors (Grid Movement)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows; 
    cout << "Enter the rows : ";
    cin >> rows;

    int cols;
    cout << "Enter the cols : ";
    cin >> cols;

    // for directions : 
    
    // this is for 4 directions : 
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int i = 1, j = 1; 

    cout << "The 4 directions : " << endl;
    for(int k = 0; k < 4; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];

        // These are the neighbors of (1, 1)
        
        if(ni >= 0 &&  ni < rows && nj >= 0 && nj < cols){
            cout << "(" << ni << "," << nj << ")" << endl;
        }

    }
    return 0;
}
/*
Enter the rows : 3
Enter the cols : 3
The 4 directions : 
(0,1)
(2,1)
(1,0)
(1,2)
*/