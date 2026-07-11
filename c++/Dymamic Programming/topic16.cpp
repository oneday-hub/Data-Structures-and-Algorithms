/*
topic : leetcode : 300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/description/
 
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion : 

int solve_1(int n, vector<int> &nums, int curr, int prev){

    // base case
    if(curr == n) return 0;

    // 1. include
    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solve_1(n, a, curr + 1, curr);
    
    // 2. exclude 
    int exclude = 0  + solve(n, a, curr + 1, prev);

    return max(include, exclude);
    
}   


// 2. Recursion  + Memo

int solve_2(int n, vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
    // base case
    if(curr == n) return 0;

    if(dp[curr][prev + 1] != -1) return dp[curr][prev+1];


    int include = 0; 
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + solve_2(n, nums, curr + 1, curr, dp);

    int exclude = 0 + solve_2(n, nums, curr + 1, prev, dp);

    return dp[curr][prev + 1] = max(include, exclude);
}

// 3. Tabulation 

int solve_3(int n, vector<int> &nums){

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    for(int curr = n -1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1; prev--){

            int include = 0; 
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr + 1][curr + 1];

            int exclude = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// 4. space optimization 

int solve_4(int n, vector<int> &nums){


    vector<int> currrow(n + 1, 0);
    vector<int> nextrow(n + 1, 0);


    for(int curr = n -1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1; prev--){

            // include
            int include = 0; 
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + nextrow[curr + 1];

            // exclude
            int exclude = 0 + nextrow[prev + 1];

            currrow[prev + 1] = max(include, exclude);
        }
        nextrow = currrow;
    }
    return next[0];
}

// 5. DP with Binary 

int solve_5(int n, vector<int> &nums){
    if( n == 0) return 0;

    vector<int> ans;
    ans.push_back(nums[0]);
  
    for(int i = 1; i < n; i++){
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }else{

            // find the index just greater or equal to element in ans
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();

            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthofLIS(vector<int> &nums){
    int n  = nums.size();

    // return solve_1(n, nums, 0, -1);

    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    //     return solve_2(n, nums, 0, -1, dp);

    //return solve_3(n, nums);

    // return solve_4(n, nums);

    return solve_5(n, nums);
}


int main() {
    
    return 0;
}