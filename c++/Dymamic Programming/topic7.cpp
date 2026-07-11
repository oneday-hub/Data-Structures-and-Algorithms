// problem : Ninja and fence / Paint Fence

/*
1️⃣ Problem Statement (Simplified)

You are given:
n = number of fence posts
k = number of colors

You must paint the fence such that:
✅ No more than 2 adjacent posts have the same color
Find the number of ways to paint the fence.

2️⃣ Example
n = 3
k = 2

Colors: A, B (that is k)

Valid ways:
A A B
A B A
A B B
B B A
B A B
B A A

Answer : 6
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int multi(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

// 1. Recursion : 
int solve(int n, int k){
    // base case
    if(n == 1) return k;
    if(n == 2){
        return add(k, multi(k, k-1));
    }

    int ans = add(multi(solve(n - 2, k),k-1), multi(solve(n - 1, k), k - 1));
    return ans;
}


// 2. Recursion + Memorization 
int solve_2(int n, int k, vector<int> &dp){
    // base case
    if(n == 1) return k;
    if(n == 2){
        return add(k , multi(k, k-1));
    }

    if(dp[n] != -1) return dp[n];

    dp[n] = add(multi(solve_2(n-2, k, dp), k-1), 
                multi(solve_2(n-1, k, dp), k-1));
    return dp[n];
}
// 3. Tabulation 
int solve_3(int n, int k){
    vector<int> dp(n + 1, 0);
    dp[1]= k;
    dp[2] = add(k, multi(k, k-1));

    for(int  i = 3; i <= n; i++){
        dp[i] = add(multi(dp[i - 2], k-1), 
                    multi(dp[i - 1], k-1));

    }
    return dp[n];
}

// 4. space optimization : 
int solve_4(int n, int k){
    int prev2 = k; 
    int prev1 = add(k, multi(k, k-1));

    for(int i = 3; i<=n; i++){
        int ans = add(multi(prev2, k-1),
                    multi(prev1, k-1));

                    prev2 = prev1;
                    prev1 = ans;
    }
    return prev1;
}


int numberofWays(int n, int k){
    // 1. Recursion 
   // return solve(n, k);

   // 2. Recursion + Memorization 
//    vector<int> dp(n+1, -1);
//    return solve_2(n, k, dp);

   // 3. Tabulation : 
   return solve_3(n, k);
}

int main() {
    int n; 
    cout << "Enter the no of fence (n) : ";
    cin >> n; 

    int k; 
    cout << "Enter no of colours (k) : ";
    cin >> k; 

    cout << numberofWays(n, k) << endl;
    return 0;
    
}