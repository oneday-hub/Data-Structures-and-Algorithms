// lecture : Lecture 135: Longest Common Subsequence || DP on Strings

   
#include <bits/stdc++.h>
using namespace std;

// 1. Recurrsion
int solve1(string &a, string &b, int i, int j){
    if(i == a.size()) return 0;

    if(j == b.size()) return 0;

    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + solve1(a, b, i + 1, j + 1);
    }else{
        ans = max(solve1(a, b, i + 1, j), solve1(a, b, i, j+1));
    }
    return ans;
}

// 2. Recurrsion + Memo
int solve2(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(i == a.size()) return 0;
    if(j == b.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + solve2(a, b, i+1, j+1, dp);
    }else{
        ans = max(solve2(a, b, i+1, j, dp),
                    solve2(a, b, i, j+1, dp));
    }

    return dp[i][j] = ans;
}


// 3. Tabulation

int solve3(string a, string b){
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = n; i >= 0; i--){
        for(int j = m; j >= 0; j--){
            
            int ans = 0;
            if(a[i] = b[j]){
                ans = 1 + dp[i+1][j+1];
            }else{
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// space optimization

int solve4(string a, string b){
    int n = a.size();
    int m = b.size();

    vector<int> curr(n+1, 0);
    vector<int> next(m+1, 0);

    for(int i= n-1; i>= 0; i--){
        for(int j = m-1; j>= 0; j--){

            int ans = 0; 

            if(a[i] == b[j]){
                ans = 1 + next[j+1];
            }
            else{
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int longestCommonSubsequence(string a, string b){
    return solve(t1, t2, 0, 0);

    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve2(a, b, 0, 0, dp);
}

int main() {
    
    
    
    return 0;
}