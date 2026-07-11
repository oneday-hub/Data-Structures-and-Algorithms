// topic : 983 : Minimum cost for tickets :
// https://leetcode.com/problems/minimum-cost-for-tickets/description/

/*
You are given:

days[] → days you will travel
costs[] → cost of:
1-day pass
7-day pass
30-day pass

👉 Find minimum cost to cover all travel days

Example
days = [1,4,6,7,8,20]
costs = [2,7,15]

Answer = 11

🔥 Core Idea

At each travel day, you have 3 choices:

Buy 1-day pass
Buy 7-day pass
Buy 30-day pass

👉 Take minimum cost among all choices
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost, int index){
    // Base case
    if(index >= n) return 0;

    // 1 day pass
    int option1 = cost[0] + solve(n, days, cost,index + 1);


    int i;

    // 7 day pass
    for(int i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solve(n, days, cost, i);

    // 30 day pass
    for(int i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));

}

// 2. Recurrsion + Memo : top down
int solve1(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
        // base case 
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        // option 1
        int option1 = costs[0] + solve1(n, days, costs, index+1,dp);

        int i = index;
        // option 2
        while(i < n && days[i] < days[index] + 7) i++;
        int option2 = costs[1] + solve1(n, days, costs, i, dp);

        // option 3
        while(i < n && days[i] < days[index] + 30) i++;
        int option3 = costs[2] + solve1(n, days, costs, i, dp);


        dp[index] =  min({option1,option2, option3});
        return dp[index];
        
    }

// 3. Tabulation buttom up : 
int solve2(int n, vector<int> &days, vector<int> &cost){

    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k = n-1; k >= 0; k--){
        // option 1 day pass
        int option1 = cost[0] + dp[k + 1];

        int  i;
        // option 7 day pass
        for(i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        // option3 30 day pass

        for(i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

    }
    return dp[0];
}
// 4. space complexity : 

int solve4 (int n, vector<int> days, vector<int> &cost){

    int ans = 0;

    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for(int day : days){
        
        // step 1 : remove expired days
        while(!month.size() && month.front().first + 30 <= day)
            month.pop();
        
        while(!week.size() && week.front().first + 7 <= day)
            month.pop();

        // step 2 : add cost to current day
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));


        // step 3 : ans update
        ans = min{(ans + cost[0] ,week.front().second, month.front().second)};
    }
    return ans;
}



int minimumCoins(int n, vector<int> days, vector<int> cost){
    int n = days.size();

    // 2. Recurrsion + Memorization 
    // vector<int> dp(n+1, -1);
    // return solve1(n, days, cost, 0, dp);

    // 3. Tabulation 
    return solve2(n, days, cost);

    // 4. space Optimization
    
}
int main() {
     
    
    return 0;
}