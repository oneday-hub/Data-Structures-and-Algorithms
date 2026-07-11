/*
Topic : leetcode 1824 : Minimum sideway Jumps : 


Minimum Sideway Jumps
The Setup 
Imagine a road with 3 lanes and n points (positions 0 to n).

A frog starts at point 0, lane 2
It wants to reach point n (any lane)
At each point, there may be an obstacle blocking one of the lanes


How the Frog Moves
The frog has 2 types of moves:

Forward move — Move from point i to point i+1 in the same lane (costs 0 jumps), only if point i+1 has no obstacle in that lane
Sideway jump — Switch to a different lane at the same point (costs 1 jump), only if the target lane has no obstacle at that current point


The Goal
Reach point n with the minimum number of sideways jumps (lane changes).
*/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion : 
int solve_1(vector<int> &obstacles, int currlane, int currpos){
    // base case

    int n = obstacles.size() - 1;
    if(currpos == n) return 0;

    // check currpos to pos + 1 has any obstacle
    if(currlane != obstacles[currpos + 1]){
        return solve_1(obstacles, currlane, currpos + 1);
    }else{
        // else means pos + 1 has a obstacles so : sideways jump
        // for both sideways are possible so take minimum 

        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1 + solve_1(obstacles, i, currpos));
        
        }
        return ans;
    }
}


// 2. Recursion + Memo / top - down
int solve_2(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp){

    int n = obstacles.size() - 1;
    if(currpos == n) return 0;


    if(dp[currlane][currpos] != -1) return dp[currlane][currpos];


    if(currlane != obstacles[currpos + 1]){
        return solve_2(obstacles, currlane, currpos + 1, dp);
    }else{
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1+solve_2(obstacles, i, currpos, dp));
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}


// 3. Tabulation : 


int solve_3(vector<int> &obstacles){
    int n = obstacles.size() - 1; 

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));

    // to create look at the top down base case
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currpos = n - 1; currpos >= 0; currpos--){
        for(int currlane = 1; currlane <= 3; currlane++){

            if(currlane != obstacles[currpos + 1]){
                dp[currlane][currpos] = dp[currlane][currpos + 1];

            }else{

                int ans = INT_MAX;
                for(int i = 1; i <= 3; i++){
                    if(currlane != i && obstacles[currpos] != i)

                        ans = min(ans, 1 + dp[i][currpos + 1]);
                    }
                dp[currlane][currpos] = ans
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}


// 4. space optimized solution : 

int solve_3(vector<int> &obstacles){
    int n = obstacles.size() - 1; 

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));


    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    // to create look at the top down base case
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currpos = n - 1; currpos >= 0; currpos--){
        for(int currlane = 1; currlane <= 3; currlane++){

            if(currlane != obstacles[currpos + 1]){
                curr[currlane] = next[currlane];

            }else{
                //sideways jump
                int ans = INT_MAX;
                for(int i = 1; i <= 3; i++){
                    if(currlane != i && obstacles[currpos] != i)

                        ans = min(ans, 1 + next[i]);
                    }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}


int minSideJumps(vector<int> &obstacles){
    // return solve_1(obstacles, 2, 0);

    // vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
    // return solve_2(obstacles, 2, 0, dp);

    return solve_3(obstacles);

}

int main() {
    
    return 0;
}