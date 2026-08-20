/* lecture : 128 : Guess Number Higher or Lower

leetcode : 375. Guess Number Higher or Lower II
https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/


*/
#include <bits/stdc++.h>
using namespace std;
// recurrsion 
int f(int start, int end){
    if(start >= end) return 0;

    int ans = INT_MAX;
    for(int i = start; i <= end; i++){
        ans = min(ans, i + max(f(start, i - 1), f(i + 1, end)));
    }
    return ans;
}

// recurrsion + memo

int f2(int start, int end, vector<vector<int>> &dp){
    if(start >= end) return 0;

    if(dp[start][end] != -1) return dp[start][end];
    
    int ans = INT_MAX;
    
    for(int i = start; i <= end; i++){
        ans = min(ans, i + max(f2(start, i - 1, dp), f2(i + 1, end, dp)));
    }

    dp[start][end] = ans;
    return dp[start][end];


}

// tabulation 

int f3(int n){
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    
    for(int start = n; start >= 1; start--){
        for(int end = start; end <= n; end++){

            if(start == end) contine;
            else{
                int ans = INT_MAX;
                for(int i = start;  i <= end; i++){
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    dp[1][n];
}
int getMoneyAmount(int n){
    // recurrsion 
    return f(0, n);

    // recurrsion + memo
    vector<vector<int>> dp(n + 2, vector<int> (n + 2, -1));
    return f2(1, n, dp);


    // tabulation 
    return f3(0, n);
}
int main() {
    
    return 0;
}