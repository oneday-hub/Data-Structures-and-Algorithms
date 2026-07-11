// topic 13 : leetcode 1039 : Minimum Score Triangulation of polygon
/*
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

Problem: Minimum Score Triangulation of Polygon

👉 You are given an array:

values = [v0, v1, v2, ..., vn-1]

Think of this as:
👉 These are vertices of a polygon
👉 Each value is written on a vertex

🔷 Step 1: Visualize the Polygon

Example:

values = [1, 3, 1, 4]

Imagine a shape like this (connected in a loop):

      (1)
     /   \
   (3)   (4)
     \   /
      (1)
🔺 Step 2: What is Triangulation?

👉 You need to divide the polygon into triangles

Rules:

Use only existing vertices
Do NOT overlap triangles
Use diagonals to split
🎯 Step 3: Cost of a Triangle

If a triangle has vertices:

i, j, k

Then:

cost = values[i] * values[j] * values[k]
🧠 Step 4: Goal

👉 Try all possible ways to divide into triangles
👉 Return minimum total cost
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Recursion 
int solve_1(vector<int> &values, int i , int j){
  if(i+1 == j) return 0;

  int ans = INT_MAX;
  for(int k = i+1; k < j; k++){
    ans = min(ans, values[k] * values[i] * values[j] + solve_1(values, i, k) + solve_1(values, k, j));
  }
  return ans;
}

// 2. Recursion + Memo
int solve_2(vector<int> &values, int i, int j, vector<vector<int>> &dp){
  // base case
  if(i + 1 == j) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int ans = INT_MAX;

  for(int k = i+1; k < j; k++){
    ans = min(ans, values[k] * values[i] * values[j] + solve_2(values, i, k, dp) + solve_2(values, k, j, dp));
  }
  dp[i][j] = ans;
  return dp[i][j];

}

// 3. Buttom up (tabulation)
int solve_3(vector<int> &values){
  int n = values.size();
  vector<vector<int>> dp(n, vector<int> (n , 0));

  for(int i = n -1; i >= 0; i--){
    for(int j = i+2; j < n; j++){

      for(int k = i+1; k < j; k++){
      ans = min(ans, values[k] * values[i] * values[j] + dp[i][k] + dp[k][j]);
    }

    dp[i][j] = ans;
    

    }
  }
  return dp[0][n-1];
}

int minSoreTriangulation(vector<int> &values){
  // 1. Recursion 
  int n = values.size();
  return solve_1(values, 0, n-1);

  // 2. Recursion + Memo
  int n = values.size();
  vector<vector<int>> dp(n, vector<int> (n, -1));
  return solve_2(values, 0, n-1, dp);
}
int main() {
    
    return 0;
}