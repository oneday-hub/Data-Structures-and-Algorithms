/*
topic : leetcode 1388 : Pizza with 3n slices
https://leetcode.com/problems/pizza-with-3n-slices/description/

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of 
slice sizes that you can pick.

 Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. 
Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:


Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion + Memorization

int solve(int index, int endindex, vector<int> &slices, int n, vector<vector<int>> &dp){
    // base case
    if(n == 0 || index > endindex) return 0;

    if(dp[index][n] != -1) return dp[index][n];
    
    int take = slices[index] + solve(index + 2, endindex, slices, n - 1, dp);
    int nottake = 0 + solve(index + 1, endindex, slices, n, dp);

    return dp[index][n] = max(take, nottake);
}

// 2. Tabulation : 

int solve2(vector<int> &slices){
    int k = slices.size();

    vector<vector<int>> dp1(k, vector<int>(k, 0));

    for(int index = k - 2; index >= 0; index--){
        for(int n = 1; n <= k/3; n++){

            int take = slices[index] + dp1[index + 2][n - 1];
            int nottake = 0 + dp1[index + 1][n];

            dp1[index][n] = max(take, nottake);
        }
    }

    int case1 = dp[0][k/3];

    vector<vector<int>> dp2(k, vector<int>(k, 0));

    for(int index = k - 1; index >= 1; index--){
        for(int n = 1; n <= k/3; n++){

            int take = slices[index] + dp2[index + 2][n - 1];
            int nottake = 0 + dp2[index + 1][n];

            dp2[index][n] = max(take, nottake);
        }
    }

    int case2 = dp2[1][k/3];

    return max(case1, case2);

}


// 3. space optimization
    int solve3(vector<int> &slices){

    int k = slices.size();

    //vector<vector<int>> dp1(k, vector<int>(k, 0));
    
    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);


    for(int index = k - 2; index >= 0; index--){
        for(int n = 1; n <= k/3; n++){

            int take = slices[index] + next1[n - 1];
            int nottake = 0 + curr1[n];

            dp1[index][n] = max(take, nottake);
        }
        next1 = curr1;
        curr1 = prev1;
    }

    int case1 = dp[0][k/3];

    // vector<vector<int>> dp2(k, vector<int>(k, 0));


    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);


    for(int index = k - 1; index >= 1; index--){
        for(int n = 1; n <= k/3; n++){

            int take = slices[index] + next2[n - 1];
            int nottake = 0 + curr2[n];

            dp2[index][n] = max(take, nottake);
        }
    }

    int case2 = dp2[1][k/3];

    return max(case1, case2);

}



int maxSizeSlices(vector<int> &slices){
    // int k = slices.size();

    // int case1 = solve(0, k - 2, slices, k/3);
    // int case2 = solve(1, k - 1, slices, k/3);

    // return max(case1, case2);

    // 2. Recursion + Memorization  : 
    // int k = slices.size();
    // vector<vecto<int>> dp1(k, vector<int>(k + 1, -1));
    // int case1 = solve(0, k - 2, slices, k/3, dp1);
    
    // vector<vecto<int>> dp2(k, vector<int>(k + 1, -1));
    // int case2 = solve(1, k - 1, slices, k/3, dp2);

    // return max(case1, case2);

    // 3. Tabulation 
    return solve2(slices);
}
int main() {
    int n; 
    cin >> n; 

    vector<int> slices(n);
    for(int i = 0; i < n; i++) cin >> slices[i];

    cout << maxSizeSlices(slices) << endl;
    return 0;
}