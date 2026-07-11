/*
problem : Common Divisors (Sieve inspired gcd logic for competitive)
          Question : you are given an array og n positive integers.
          you need to find two integers such that their greatest divisors is as large as possible.

          output : print the maximum gcd 

          2 approaches : 1. frequency count
                        2. sieve like method
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    // Frequency array
    vector<int> freq(maxVal + 1, 0);
    for (int x : a) {
        freq[x]++;
    }

    // Try all possible GCDs from largest
    for (int g = maxVal; g >= 1; g--) {
        int count = 0;

        // count multiples of g
        for (int multiple = g; multiple <= maxVal; multiple += g) {
            count += freq[multiple];

            if (count >= 2) {
                cout << g << "\n";
                return 0;
            }
        }
    }

    return 0;
}