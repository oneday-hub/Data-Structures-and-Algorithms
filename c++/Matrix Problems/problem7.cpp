// topic 7 : 8 directions : 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int r;
    cout << "Enter the r : ";
    cin >> r; 

    int c; 
    cout << "Enter the c : ";
    cin >> c; 

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int i = 1, j = 1; 
    cout << "The 8 directions : " << endl;
    for(int k = 0; k < 8; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && ni < r && nj >= 0 && nj < c){
            cout << "(" << ni << "," << nj << ")" << endl;
        }
    }
    return 0;
}
/*
Enter the r : 3
Enter the c : 3
The 8 directions : 
(0,0)
(0,1)
(0,2)
(1,0)
(1,2)
(2,0)
(2,1)
(2,2)
*/