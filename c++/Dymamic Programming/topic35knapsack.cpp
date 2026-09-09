// lecture 110: 0/1 KnapSack Problem || learn 2-D DP Concept || DP Series

/*
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. Considering the 
constraints of the maximum weight that a knapsack can carry, you have to find and 
return the maximum value that a thief can generate by stealing items.

Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3

Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/


#include <bits/stdc++.h> 
using namespace std;

// 1. recurrsion

int solve1(vector<int> &weight, vector<int> &value, int index, int maxWeight){
	// base case;
	if(index == 0){
		if(weight[0] <= maxWeight){
			return value[0];
		}else{
			return 0;
		}
	}

	int include = 0;
	if(weight[index] <= maxWeight){
		include = value[index] + solve1(weight, value, index-1, maxWeight - weight[index]);
	}
	int exclude = 0 + solve1(weight, value, index-1, maxWeight);

	int ans = max(exclude, include);
	return ans;
}

// 2. Recurrsion + Memo
int solve2(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>>&dp){

	// base case
	if(index == 0){
		if(weight[0] <= maxWeight){
			return value[0];
		}else{
			return 0;
		}
	}
	if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

	int include = 0;
	if(weight[index] <= maxWeight){
		include = value[index] + solve2(weight, value, index-1, maxWeight - weight[index], dp);
	}
	int exclude = 0 + solve2(weight, value, index-1, maxWeight, dp);

	int ans = max(exclude, include);
	return dp[index][maxWeight] = ans;
	
}

// 3. tabulation 
int solve3(vector<int> &weight, vector<int> &value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for(int w = weight[0]; w <= maxWeight; w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }else{
            dp[0][w] = 0;
        }
    }

    for(int index = 1; index < n; index++){
        for(int w = 0; w <= maxWeight; w++){
            int include = 0; 
            if(weight[index] <= w){
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            int exclude = 0 + dp[index-1][maxWeight];

            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n-1][maxWeight];
}

// 4. space optimization

int solve4(){

    vector<int> prev(maxWeight + 1, 0); 
    vector<int> curr(maxWeight + 1, 0);

    for(int w = weight[0]; w <= maxWeight; w++){
        if(weight[0] <= capacity){
            prev[w] = value[0];
        }else{
            prev[w] = 0;
        }
    }

    for(int index = 1; index < n; index++){
        for(int w = 0; w <= maxWeight; w++){
            int include = 0; 
            if(weight[index] <= w){
                include = value[index] + prev[w - weight[index]];
            }
            int exclude = 0 + prev[maxWeight];

            curr[w] = max(exclude, include);
        }
        prev = curr;
        
    }
    return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){

	// return solve1(weight, value, n-1, maxWeight);

	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return solve2(weight, value, n-1, maxWeight, dp);

    return solve3(weight, value, n-1, maxWeight);
}























