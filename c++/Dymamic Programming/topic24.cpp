/* lecture : 127 : Unique Binary Search tree 
leetcode : 96. Unique Binary Search Trees

https://leetcode.com/problems/unique-binary-search-trees/description/

------- Catalan Numbers ----------------

Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

// Recurrsion : 
int solve1(int n){
    if(n <= 1) return 1; 

    int ans = 0; 

    for(int i = 1; i <= n; i++){
        ans += solve1(i - 1) * solve1(n - i);
    }

    return ans; 
}

// Recurrsion + Memo
int solve2(int n, vector<int> &dp){
    if(n <= 1) return 1; 

    int ans = 0; 

    if(dp[n] != -1) return dp[n];

    for(int i = 1; i <= n; i++){
        ans += solve2(i - 1, dp) * solve2(n - i, dp);
    }

    return dp[n] = ans;
}

// Tabulation 
int solve3(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}
int main() {
    
    int n; 
    cout << "Enter the no of nodes : ";
    cin >> n; 

    cout << solve3(n) << endl;
    return 0;
}