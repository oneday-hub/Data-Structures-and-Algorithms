// lecture 133 : leetcode 188. Best Time to Buy and Sell Stock IV

/*
You are given an integer array prices where prices[i] is the price of a given 
stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: 
i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. 
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
*/

#include <bits/stdc++.h>
using namespace std;
// 1. Recurrsion
int solve1(){

}

// 2. Recurrsion + Memorization
int solve2(){

}

// 3. Tabulation
int solve3(){

}

// 4. space optimized solution
int solve4(vector<int> &prices, int k){
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));

    for(int index = n - 1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            for(int limit = 1; limit <= k; limit++){
                
                int profit = 0; 
                if(buy){
                    int buykaro = -prices[index] + next[0][limit];
                    int skipkaro = 0 + next[1][limit];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index] + next[1][limit - 1];
                    int skipkaro = 0 + next[0][limit];
                    profit = max(sellkaro, skipkaro);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;

    }
    return next[1][k];
}

// 5. using Transaction number : Recurrsion
int solve5(int index, int operationNo, int k, vector<int> &prices){
    if(index == prices.size()) return 0;
    
    if(operationNo == 2 * k) return 0;

    int profit = 0;

    // by observation even number is associated to = buy (that is allowed)
    if(operationNo % 2 == 0){
        // buy allowed
        
        int buykaro = -prices[index] + solve5(index + 1, operationNo + 1, k, prices);
        int skipkaro = 0 + solve5(index + 1, operationNo, k, prices);
        profit = max(buykaro, skipkaro);

    }else{
        int sellkaro = prices[index] + solve5(index + 1, operationNo + 1, k, prices);
        int skipkaro = 0 + solve5(index + 1, operationNo, k, prices);
        profit = max(sellkaro, skipkaro);

    }
    return profit;
}


// 5(a) : Transaction Number optimization
// adding memorization in this solution 

int solve_5a(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp){
    if(index == prices.size()) return 0;
    if(operationNo = 2 * k) return 0;

    if(dp[index][operationNo] != 0) return dp[index][operationNo];

    
    int profit = 0;
    if(operationNo % 2 == 0){
        int buykaro = -prices[index] + solve_5a(index + 1, operationNo+1, k, prices, dp);
        int skipkaro = 0 + solve_5a(index + 1, operationNo, k, prices, dp);
        profit = max(buykaro, skipkaro);
    }else{
        int sellkaro = prices[index] + solve_5a(index + 1, operationNo + 1, k, prices, dp);
        int skipkaro = 0 + solve_5a(index + 1, operationNo + 1, k, prices, dp);
        profit = max(sellkaro, skipkaro);
    }

    return dp[index][operationNo] = profit;
}

int maxProfit(vector<int> &prices, int k){
    // return solve4(prices, k);

    //return solve5(0, 0, k, prices);
    
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    return solve_5a(0, 0, k, prices, dp);
}
int main() {
    
    return 0;
}