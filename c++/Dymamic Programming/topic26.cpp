/*
lecture : 129 : 1130 : Minimum Cost Tree From Leaf Values
leetcode : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

Given an array arr of positive integers, consider all binary trees such that:

-- Each node has either 0 or 2 children;

-- The values of arr correspond to the values of each leaf in an in-order traversal of the tree.


-- The value of each non-leaf node is equal to the product of the largest leaf value in its left 
   and right subtree, respectively.


Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Input: arr = [4,11]
Output: 44
*/


#include <bits/stdc++.h>
using namespace std;

// Recurrsion 
// int f(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right){
   
//    // leaf node
//    if(left == right){
//       return 0;
//    }

//    int ans = INT_MAX;

//    for(int i = left; i < right; i++){
//       ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + f(arr, maxi, left, i) + f(arr, maxi, i + 1, right));
//    }
//    return ans;
// }

// Recurrsion + memo
int func2(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
   // base case
   if(left == right) return 0;

   if(dp[left][right] != -1 ) return dp[left][right];

   int ans = INT_MAX;

   for(int i = left; i < right; i++){
      int rootcost = maxi[{left, i}] * maxi[{i + 1, right}];
      int leftcost = func2(arr, maxi, left, i, dp);
      int rightcost = func2(arr, maxi, i + 1, right, dp);

      ans = min(ans, rootcost + leftcost + rightcost);
   }

   return dp[left][right] = ans;
}

int mctFromleafValues(vector<int> &arr){
   int n = arr.size();

   map<pair<int, int>, int> maxi;

   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

   for(int i = 0; i < arr.size(); i++){
      maxi[{i, i}] = arr[i];

      for(int j = i + 1; j < arr.size(); j++){
         maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
      }
   }

   // recurrsion 
   // return f(arr, maxi, 0, arr.size() - 1);

   // recurrsion + memo

   return func2(arr, maxi, 0, n - 1, dp);
}

int main() { 
   vector<int> arr = {6, 2, 4};
   cout << mctFromleafValues(arr) << endl;
   return 0;
}