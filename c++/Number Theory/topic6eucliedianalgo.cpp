// Euclidean Algorithms

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 1. Euclidean (modulo) - Iterative (preferred in cp)
ll gcd_euclid(ll a, ll b){

    a = llabs(a);
    b = llabs(b);

    while(b != 0){
        ll r = a % b;
        a = b; 
        b = r;
    }
    return a; // last non - zero = gcd
}

// 2. Euclidean (modulo) - Recursive (short and clean)

ll gcd_recurrsion(ll a, ll b){
    a = llabs(a);
    b = llabs(b);

    return (b == 0) ? a : gcd_recurrsion(b, a % b);
}

// calculation LCM

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}
int main() {
    
    return 0;
}