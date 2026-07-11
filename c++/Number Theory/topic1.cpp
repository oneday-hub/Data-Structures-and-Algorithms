// problem : Counting Divisors : 

// 2 approaches : 1. Naive 
//                2. optimal Approach O(logk)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

vector<int> sieve(MAX + 1, 0);

// Build SPF (Smallest Prime Factor)
void precompute() {
    for (int i = 2; i <= MAX; i++) {
        if (sieve[i] == 0) { // i is prime
            for (int j = i; j <= MAX; j += i) {
                if (sieve[j] == 0) {
                    sieve[j] = i; // store smallest prime factor
                }
            }
        }
    }
}

// Count number of factors
void solve() {
    int n;
    cin >> n;

    int res = 1;

    while (n > 1) {
        int spf = sieve[n];
        int alpha = 0;

        while (n % spf == 0) {
            n /= spf;
            alpha++;
        }

        res *= (alpha + 1);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // VERY IMPORTANT

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}