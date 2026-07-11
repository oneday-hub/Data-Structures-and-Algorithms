/*
topic : leetcode : 1402 : Reducing Dishes 
https://leetcode.com/problems/reducing-dishes/

A chef has collected data on the satisfaction level of his n dishes. 
Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes 
multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some 
amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient 
will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/



#include <bits/stdc++.h>
using namespace std;

// 1. Recursion : 
int solve_1(vector<int> &satisfaction, int index, int time){
    // base case
    if(index == satisfaction.size())
        return 0;
    
    int include = satisfaction[index] * (time + 1) + solve_1(satisfaction, index + 1, time + 1);
    int exclude = 0 + solve(satisfaction, index + 1, time);

    return max(include, exclude);
}


// 2. Recursion + Memo
int solve_2(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
    // base case
    if(index == satisfaction.size())
        return 0;
    
    if(dp[index][time] == -1) return dp[index][time];

    
    int include = satisfaction[index] * (time + 1) + solve_2(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solve_2(satisfaction, index + 1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

// 3. buttom up : 

int solve_3(vector<int> &satisfaction){
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int> (n +1, 0));

    for(int index = n -1; index >= 0; index--){
        for(int time = index; time >= 0; time --){

            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

// 4. space optimization solution 

int solve_4(vector<int> &satisfaction){
    int n = satisfaction.size();
    // vector<vector<int>> dp(n + 1, vector<int> (n +1, 0));

    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for(int index = n -1; index >= 0; index--){
        for(int time = index; time >= 0; time --){

            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = 0 + next[time];

            curr[time] = max(include, exclude);
        }
        next = curr
    }

    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction){

    // 1. Recursion
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);


    // 2. Recursion + Memo
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int> (n + 1, -1));
    return solve_2(satisfaction, 0, 0);


    //
    return solve_3(satisfaction);

    //
    return solve_4(satisfaction);
}
int main() {
    
    return 0;
}