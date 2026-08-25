// lecture 131 : best time to buy and sell stock (part 2);
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the 
stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring 
you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to 
achieve the maximum profit of 0.
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Recurrsion
int solve1(int index, int buy, vector<int> &prices){
    if(index == prices.size())
        return 0;

    int profit = 0;
    if(buy){
        int buykaro = -prices[index] + solve1(index + 1, 0, prices);
        int skipkaro = 0 + solve1(index + 1, 1, prices);
        profit = max(buykaro, skipkaro);
    }else{
        int sellkaro = prices[index] + solve1(index + 1, 1, prices);
        int skipkaro = 0 + solve1(index + 1, 0, prices);
        profit = max(sellkaro, skipkaro);
    }
    return profit;
}

// 2.Recurrsion + Memorization

int solve2(int index, int buy, vector<int> &prices, vector<vector<int>> &dp){
    if(index == prices.size()) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if(buy){
        int buykaro = -prices[index] + solve2(index + 1, 0, prices, dp);
        int skipkaro = 0 + solve2(index + 1, 1, prices, dp);
        profit = max(buykaro, skipkaro);
    }else{
        int sellkaro = prices[index] + solve2(index + 1, 0, prices, dp);
        int skipkaro = 0 + solve2(index + 1, 0, prices, dp);
        profit = max(sellkaro, skipkaro);
    }
    return dp[index][buy] = profit;
}
// tabulation
int solve3(vector<int> &prices){
    vector<vector<int>>dp(n + 1, vector<int>(2, 0));
    // so as we know look at the base case 
    // already inialized with zero

    for(int index = n - 1;  index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){

            int profit = 0;
            if(buy){
                int buykaro = -prices[index] + dp[index + 1][0];
                int skipkaro = 0 + dp[index + 1][1];
                profit = max(buykaro, skipkaro);
            }else{
                int sellkaro = prices[index] + dp[index + 1][1];
                int skipkaro = 0 + dp[index + 1][0];
                profit = max(sellkaro, skipkaro);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}


int maxprofit(vector<int> &prices){
    // return solve1(0, 1, prices);

    
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve1(0, 1, prices, dp);
}
int main() {
    
    return 0;
}