// topic : 230B : T - primes
// https://codeforces.com/problemset/problem/230/B

/* We know that prime numbers are positive integers that have exactly two distinct positive divisors. 
Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6;

vector<bool> isprime(MAX + 1, true);

void sieve(){
    isprime[0] = isprime[1] = false;

    for(int i = 2; i*i <= MAX; i++){
        if(isprime[i]){
            for(int j = i*i; j <= MAX; j += i){
                isprime[j] = false;
            }
        }
    }
}

int main() {
   sieve();
   ll t; 
   cin >> t; 
   while(t--){
    ll n; 
    cin >> n ;

    ll root = sqrt(n);

    if(root * root == n && isprime[root])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
   }

   return 0;
}