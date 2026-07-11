// topic : Combination sum IV 

/*
Given an array of distinct integers nums and a target integer target, return the number 
of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

For Example : 
You are given:

nums = [1,2,3]
target = 4

Find:

Number of ways to form target using nums

⚠️ Order matters (this is VERY important)
*/
#include <bits/stdc++.h>
using namespace std;

// Recurrsion : 
int solve(vector<int> &nums, int tar){
    // base case

    if(tar < 0) return 0;
    if(tar == 0) return 1;

    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        ans += solve(nums, tar - nums[i]);
    }
    return ans;
}

// 2. Recursion + Memorization 
int solve1(vector<int> &nums, int tar, vector<int> &dp){
    if(tar < 0) return 0;
    if(tar == 0) return 1; 

    if(dp[tar] != -1) return dp[tar];
    int ans = 0;
    
    for(int i = 0; i < nums.size(); i++){
        ans += solve1(nums, tar - nums[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}


int findways(vector<int> &nums, int tar){
    // 1. recurrsion :
    // return solve(nums, tar);

    // 2. recurrsion + memo
    vector<int> dp(tar + 1, -1);
    return solve1(nums, tar, dp);
}


int main() {
    int n; 
    cout << "Enter the no of elements in nums : ";
    cin >> n; 

    vector<int> nums(n);
    for(int i = 0; i< n;i++){
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    cout << findways(nums, target);
    return 0;
}