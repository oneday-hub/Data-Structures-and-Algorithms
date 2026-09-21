// lecture : 137 lc : 72 : edit distance
/*
Given two strings word1 and word2, return the minimum number of operations 
required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
*/

#include <bits/stdc++.h>
using namespace std;


// 1. Recurrsion
int solve1(string a, string b, int i, int j){
    // base case
    if(i == a.length())
        return b.length() - j;
    
    if(j == b.length())
        return a.length() - i;

    int ans = 0;

    if(a[i] == b[j]){
        return solve1(a, b, i+1, j+1);
    }else{
        int insertans = 1 + solve1(a, b, i, j+1);
        int deleteans = 1 + solve1(a, b, i+1, j);
        int replaceans = 1 + solve1(a, b, i+1, j+1);

        ans = min(insertans, min(deleteans, replaceans));
    }

    return ans;
}

// 2. Recurrsion + Memorization
int solve2(string a, string b, int i, int j, vector<vector<int>> &dp){
    // base case
    if(i == a.length()){
        return b.length() - j;
    }

    if(j == b.length()){
        return a.length() - i;
    }

    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;

    if(a[i] == b[j]){
        return solve2(a, b, i+1, j+1, dp);
    }else{
        int insertans = 1 + solve2(a, b, i, j+1, dp);
        int deleteans = 1 + solve2(a, b, i+1, j, dp);
        int replaceans = 1 + solve2(a, b, i+1, j+1, dp);

        ans = max(insertans, max(deleteans, replaceans));
    }

    return dp[i][j] = ans;
}

int solve3(string a, string b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int j = 0; j < m; j++){
        dp[n][j] = m - j;
    }

    for(int i = 0; i < n; i++){
        dp[i][m] = n - i;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){

            int ans = 0; 

            if(a[i] == b[j]){
                ans =  dp[i+1][j+1];
            }else{
                int insertans = 1 + dp[i][j+1];
                int deleteans = 1 + dp[i+1][j];
                int replaceans = 1 + dp[i+1][j+1];

                ans = min(insertans, min(deleteans, replaceans));
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int minDistance(string w1, string w2){
    // return solve1(word1, word2, 0, 0);

    
    vector<vector<int>> dp(w1.size(), vector<int>(w2.size(), -1));
    return solve2(w1, w2, 0, 0, dp);
}
int main() {
   
    return 0;
}