// topic 3 : Minimum no of coins : 

#include <bits/stdc++.h>
using namespace std;

int solve_Recursion(vector<int> &num, int x){
    //base case
    if(x == 0){
        return 0;
    }

    if(x < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i = 0; i<num.size(); i++){
        int ans = solve_Recursion(num, x - num[i]);

        if(ans != INT_MAX) 
            mini = min(mini, 1 + ans);
    }

    return mini;
}
int solve_Memo(vector<int> &num, int x, vector<int> &dp){
    //base case
    if(x == 0){
        return 0;
    }

    if(x < 0){
        return INT_MAX;
    }


    if(dp[x] != -1){
        return dp[x];
    }


    int mini = INT_MAX;

    for(int i = 0; i<num.size(); i++){
        int ans = solve_Memo(num, x - num[i], dp);

        if(ans != INT_MAX) 
            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;

    return mini;
}
int solve_Tabulation(vector<int> &num, int x){
    
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i<x; i++){
        for(int j = 0; j< num.size(); j++){
            
            if(i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - num[j]]);
        }
    }
    if(dp[x] == INT_MAX)
        return -1;
    
    return dp[x];
}

int minmumElements(vector<int> &num, int x){

    // 1. Recursion 

    // int ans = solve_Recursion(num, x);
    // if(ans == INT_MAX)
    //     return -1;


    // 2. Recursion + Memorization 

    // vector<int> dp(x + 1, -1);
    // int ans = solve_Memo(num, x, dp);

    // if(ans == INT_MAX)
    //     return -1;
    // else
    //     return ans;

    // 3. Tabulation 

    return solve_Tabulation(num, x);

}

int main() {
    
    int n, x;
    cin >> n;

    vector<int> num(n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    cin >> x;

    cout <<minmumElements(num, x);

    return 0;

}
    
  