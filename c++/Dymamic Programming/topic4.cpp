
// topic 4 : Maximum sum of non adjacent elements

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion 
int solve(vector<int> &nums, int n){

    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1);

    return max(include, exclude);

}

// 2. Recursion + Memorization 
int solve_2(vector<int> &nums, int n, vector<int> &dp){

    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    if(dp[n] != -1) return dp[n];

    
    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1);

    dp[n] = max(include, exclude);
    return dp[n];
    //return max(include, exclude);

}

// 3. Tabulation 

int solve_3(vector<int> &nums){

    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i = 1; i<n; i++){
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;

        dp[i] = max(include, exclude);
    }

    return dp[n - 1];

}
int maximumNonAdjacentSum(vector<int> &nums, int n){
    // 1. Recursion 
    // int n = nums.size();
    // int ans = solve(nums, n -1);
    // return ans;

    // 2. Recursion + Memorization 
    // int  n = nums.size();
    // vector<int> dp(n, -1);
    // return solve_2(nums, n-1, dp);


    // 3. tabulation 
    return solve_3(nums);

}

int main() {
    int n; 
    cin >> n; 

    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    cout << maximumNonAdjacentSum(nums, n) << endl;
    return 0;
}