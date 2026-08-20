#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
ll power(ll base, ll exponent){
    ll res = 1;

    while(exponent > 0){
        if(exponent & 1){
            res = (res * base) % MOD;
        }
        base = (base * base)% MOD;
        exponent >>= 1;
    }
    return res;
}

int main() {
    int a = 3;
    int b = 13; 

    cout << power(a, b) << endl;
    return 0;
}