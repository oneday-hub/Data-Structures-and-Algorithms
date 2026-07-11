// topic : 279 Get minimum Squares : 
// https://leetcode.com/problems/perfect-squares/description/
/*
problem : Given a number n, find the minimum count of perfect squares 
          (like 1, 4, 9, 16, …) whose sum = n

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
#include <bits/stdc++.h>
using namespace std;

// 1.Recurrsion : 

int solve(int n){
    if(n == 0) return 0;

    int ans = n;
    for(int i = 0;  i*i <= n; i++){
        ans = min(ans, 1+solve(n - i*i));
    }
    return ans;
}

// 2. Recurrsion + Memorization 
int solve1(int n, vector<int> &dp){
    if(n == 0) return 0;

    int ans = n; 
    if(dp[n] != -1) return dp[n];

    for(int i = 1; i*i <= n; i++){
        ans += min(ans, 1+solve1(n - i*i, dp));
    }

    dp[n] == ans; 
    return dp[n];
}

// 3. Tabulation :
int solve2(int n){
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j*j <= n; j++){

            if(i - j*j >= 0) 
            dp[i] = min(dp[i], 1+ dp[i - j*j]);
        }
    }
    return dp[n];
}

int minSquares(int n){
    // 1. recurrsion 
    // return solve(n);

    // 2. recurrsion + Memorization
    // vector<int> dp(n+1, -1);
    // return solve1(n, dp);

    // 3. tabulation 

    return solve2(n);
}
int main() {

    int n; 
    cin >> n; 

    //cout << minSquares(n) << endl;
    cout << minSquares(n) << endl;
    return 0;
}