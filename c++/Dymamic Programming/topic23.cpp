// topic : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
// solution : 


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int longestSubsequence(vector<int> &arr, int d){
    unordered_map<int, int> dp;

    int ans = 0; 
    for(int i = 0; i < arr.size(); i++){
        int temp = arr[i] - d;
        int tempans = 0;
        // check answer exist for temp already or not
        if(dp.count(temp))
            tempans = dp[temp];

        // current ans update
        dp[arr[i]] - 1 + tempans;

        // ans update : 
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

int main() {
    fast_io;
    
    
    return 0;
}