// topic : sieve of erotosthenes : 

// precomputed : 
#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void buildSieve(int n) {
    isPrime.assign(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n = 1000000; // max limit
    buildSieve(n);

    int q;
    cin >> q; // number of queries

    while (q--) {
        int x;
        cin >> x;

        if (isPrime[x])
            cout << "Prime\n";
        else
            cout << "Not Prime\n";
    }
}