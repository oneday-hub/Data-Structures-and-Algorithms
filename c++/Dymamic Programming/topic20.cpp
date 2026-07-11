// distinct ways pattern problems : 

// topic : 1155 : Number of dice rolls with target sum : 
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways 
(out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 109 + 7.


Problem

You are given:

n = number of dice
k = faces on each die
target = required sum
🎯 Goal

Find:

Number of ways to get target sum

Example
n = 2
k = 6
target = 7

Possible ways:

(1,6)
(2,5)
(3,4)
(4,3)
(5,2)
(6,1)

👉 Answer = 6
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


// 1. Recursion
long long solve1(int dice, int faces, int target){

    // base case
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return  0;
    if(target == 0 && dice != 0) return 0;
    if(dice == 0 && target == 0) return 1; 

    int ans = 0;
    for(int i = 1; i <= faces; i++){
        ans = ans + solve(dice - 1, faces, target - i);
    }
    return ans;
}

// 2. Recursion + Memo
long long solve2(int dice, int faces, int target, vector<vector<int>> &dp){
    // base case   
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return 0;
    if(target == 0 && dice != 0) return 0;
    if(dice == 0 && target == 0) return 1; 

    if(dp[dice][target] != -1) return dp[dice][target];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + solve2(dice - 1, faces, target - i, dp)) % mod;

    }
    return dp[dice][target] = ans;
}



// 3. tabulation 
long long solve3(int n, int k, int target){
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));

    // after analysing the base case : 
    dp[0][0] = 1;

    for(int dice = 0; dice <= d; dice++){
        for(int target = 1; target <= t; t++){

            long long ans = 0;
            for(int i = 1; i <= faces; i++){
                ans = ans + dp[dice - 1][target-i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[d][f];
}



long long numRollsToTarget(int n, int k, int target){
    // return solve1(n, k, target);

    // vector<vector<long long>> dp(n+1, vector<long long>(target + 1, -1));
    // return solve2(n, k, target, dp);

    return solve3(n, k, target);
}

int main() {
    
    
    return 0;
}