// lecture 23 : Chinese Remainder Theorem (CRT) | Intuition + Proof + Code 

// To fully implement this follow the notes go through the proof for the better understanding
// go through 2 and 3 times : 

#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Function to find gcd and x, y such that ax + by = gcd(a, b)

ll extended_gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extended_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Modular inverse using Extended Euclid

ll mod_inverse(ll a, ll m){
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if(g != 1){
        return -1;  // inverse doesn't exist
    }
    return (x % m + m) % m;
}


// Chinese Remainder Theorem
ll chinese_remainder(vector<ll> a, vector<ll> m){
    ll M = 1;
    for(auto val : m){
        M *= val;
    }

    ll x = 0;
    for(int i = 0; i < a.size(); i++){
        ll Mi = M / m[i];
        ll inv = mod_inverse(Mi, m[i]);

        x = (x + a[i] * Mi % M * inv % M) % M;
    }

    return (x + M) % M; // ensure non - negative
}

int main() {
    
    vector<ll> a = {2, 3, 2};
    vector<ll> m = {3, 5, 7};

    cout << "x = " << chinese_remainder(a, m) << endl;
    return 0;
}