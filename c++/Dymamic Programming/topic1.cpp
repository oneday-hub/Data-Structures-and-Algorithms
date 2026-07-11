// problem : Nth fibonacci number 

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : top - down approach

int fib_1(int n, vector<int> &dp){
    // base case;
    if(n <= 1){
        return n; 
    }

    // step 3 : 
    if(dp[n] != -1)
        return dp[n];
    // return fib(n-1) + fib(n-2);
    // changing to dp
    // step 2 : 
    dp[n] = fib_1(n-1, dp) + fib_1(n-2, dp);
    return dp[n];
}


// Approach 2 : Buttom - Up approach

int fib_2(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = dp[2] = 1; 

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int main() {
    int n; 
    cout << "Enter the number : ";
    cin  >> n; 

    // step 1 : create dp array
    vector<int> dp(n+1);
    for(int i = 0; i<=n; i++){
        dp[i] = -1; 
    }

    cout << "The value of fib value (top Down) : " << fib_1(n, dp) << endl;
    cout << "The value of fib value (Buttom Up) : " << fib_2(n, dp) << endl;
    
    return 0;
}