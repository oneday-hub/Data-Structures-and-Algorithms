// problem : count derangements : 

/*
1️⃣ Problem Idea

You are given n items (or people).
You must rearrange them so that no item remains in its original position.

Such permutations are called Derangements.
*/

#include <bits/stdc++.h>
using namespace std;
// 1. Recursion :
int solve(int n){
    // base case
    if(n == 1) return 0; 
    if(n == 2) return 1;

    int ans = (n - 1) * (solve(n -1) + solve(n -2));
    return ans;
}
// 2. Recursion + Memorization : 
int solve_2(int n, vector<long long int> &dp){
    if(n == 1) return 0; 
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = (n - 1) * (solve_2(n -1, dp) + solve_2(n -2, dp));
    return dp[n];
}
// 3. Tabulation : 
int solve_3(int n){
    if(n == 0) return 1;
    vector<long long int> dp(n+1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i<= n; i++){
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

// 4. space optimization 
int solve_4(int n){
    if(n == 1) return 0;
    if(n == 2) return 1; 

    long long prev2 = 0; 
    long long prev1 = 1;
    long long curr;

    for(int i = 3; i<= n; i++){
        curr = (i - 1) * (prev1 + prev2);
        prev2 = prev1; 
        prev1 = curr;
    }
    return prev1; 
}

long long int countDerangements(int n){

    // recursion + Memorization 
    // vector<long long int> dp(n+1, -1);
    // return solve_2(n, dp);

    // 3. Tabulation 
    return solve_3(n);

    // 4. space optimization 
    //return solve_4(n);
}
int main() {
    int n; 
    cout << "Enter the number : ";
    cin >> n; 

    cout << "Ans : " << countDerangements(n) << endl;
    return 0;
}