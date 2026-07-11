// question : A. Almost Prime 
// https://codeforces.com/problemset/problem/26/A

/*
A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are 
almost prime, while 4, 8, 9, 42 are not. Find the amount of almost prime numbers which are between 1 and n, inclusive.

Input
Input contains one integer number n (1 ≤ n ≤ 3000).

Output
Output the amount of almost prime numbers between 1 and n, inclusive.
*/
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fast_io;
    int n; 
        cin >> n; 

        vector<int> seive(n + 1, 0);
        for(int i = 2; i<= n; i++){
            if(seive[i] == 0){
                for(int j = i; j <= n; j+=i){
                    seive[j]++;
                }
            }
        }
        int count = 0; 
        for(int i = 2; i <= n; i++){
            if(seive[i] == 2){
                count++;
            }
        }
        cout << count << endl;
    return 0;
}

