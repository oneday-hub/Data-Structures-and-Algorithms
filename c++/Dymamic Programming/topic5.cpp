// topic 5 : cut into segments : 
/*
1️⃣ Problem

You are given:

n → length of rod
x, y, z → allowed cut lengths

You must cut the rod into maximum number of pieces using only these lengths.
*/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion : 

int solve(int n, int x, int y, int z){
    // base case 
    if(n == 0) return 0;

    if(n < 0) return INT_MIN;

    // only 1 variable/ 1 state is changing (n) : 
    // therefore we change use 1d array;
    int a = solve(n - x, x, y, z) + 1;   
    int b = solve(n - y, x, y, z) + 1;   
    int c = solve(n - z, x, y, z) + 1;   

    int ans = max(a , max(b, c));
    return ans;
}


// 2. Recursion + Memorization (Buttom Up);

int solve_2(int n, int x, int y, int z, vector<int> &dp){
    // base case;
    if(n == 0) return 0;

    if(n < 0) return INT_MIN;

    if(dp[n] != -1){
        return dp[n];
    }

    int a = solve_2(n - x, x, y, z, dp) + 1;
    int b = solve_2(n - y, x, y, z, dp) + 1;
    int c = solve_2(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

// 3. Tabulation 
int solve_3(int n, int x, int y, int z){

    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for(int i = 1; i<=n; i++){
        if(i - x >= 0 && dp[i-x] != INT_MIN){
        dp[i] = max(dp[i], dp[i - x] + 1); 
        // here i - x can be invalid index
        // also check dp[i - x] != - infinity that is (INT_MIN)
        }

        if(i - y >= 0 && dp[i-y] != INT_MIN){
            dp[i] = max(dp[i], dp[i - y] + 1); 
        }
        if(i - z >= 0 && dp[i-z] != INT_MIN){
            dp[i] = max(dp[i], dp[i - z] + 1); 
        }

    }

    if(dp[n] < 0)
        return 0;
    else
        return dp[n];
}
int cutSegments(int n, int x, int y, int z){

    // // 1. Recursion
    // int ans = solve(n, x, y, z);
    // if(ans < 0)
    //     return 0;
    // else
    //     return ans;

    // 2. Recursion + Memorization 

    // vector<int> dp(n + 1, -1);
    // int ans = solve_2(n, x, y, z, dp);

    // if(ans < 0)
    //     return 0;
    // else    
    //     return ans;

    // 3. tabulation 

    return solve_3(n, x, y, z);

}
int main() {
    int n, x, y, z;
    cout << "Enter the lenght of rod (n) and the segment (x, y, z) : ";
    cin >> n >> x >> y >> z;

    cout << "Ans : " << cutSegments(n, x, y, z) << endl;
    
    return 0;
}