// topic 2 : Minimun cost Climbing tree : 


/*
T.C => O(n) 
S.C => O()
*/
#include <bits/stdc++.h>
using namespace std;

// 1. recursion 
int solve(vector<int>&cost, int n){
    // Base case 
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}
// 2. recursion + memorization 
int solve_2(vector<int>&cost, int n, vector<int> &dp){
    // Base case 
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    // step 3 : 
    if(dp[n] != -1) return dp[n];

    // step 2 :
    dp[n] = cost[n] + min(solve_2(cost, n-1, dp), solve_2(cost, n-2, dp));
    return dp[n];
}
// 3 . tabulation 
int solve_3(vector<int> &cost, int n){
    vector<int> dp(n+1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i<n; i++){
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n-1], dp[n-2]);
}

// space optimization O(1)

int solve_4(vector<int> &cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2 ; i<n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1; 
        prev1 = curr; 
    }

    return min(prev1, prev2);
}
int minCostClimbingStairs(vector<int> &cost){
    // int n = cost.size();
    // int ans = min(solve(cost, n-1), solve(cost, n-2));
    // return ans;

    // using dp : because of TLE error 
    // Approach 1 : top Down : recurrsion + memorization 
    int n = cost.size();
    // step 1
    // vector<int> dp(n+1, -1);
    // int ans = min(solve_2(cost, n-1, dp), solve_2(cost, n - 2, dp));
    // return ans;


    // Approach 2 : Buttom up : tabulation 
    
    return solve_3(cost, n);


    // Approach 3 : space Optimization O(n);
    return solve_4(cost, n);
}
int main() {
    int n;
    cin >> n;

    vector<int> cost(n);

    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}

