// problem : Divisor Summation : 

// given a natural number n (1 <= n <= 500000) 
// please output the summation of all its proper divisors

// eg. 20 has 5 proper divisor : 1, 2, 4, 5, 10 and 
//      their sum = 1 + 2 + 4 + 5 + 10 = 22.

// 2 approaches : 1. sqrt(n)
//                2. log(n)


#include <bits/stdc++.h>
using namespace std;

// 1. Code (O(√n))

long long sumProperDivisors_sqrt(int n) {
    long long sum = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != n) sum += i;

            int other = n / i;
            if (other != i && other != n)
                sum += other;
        }
    }

    return sum;
}

// Code (SPF + O(log n))

const int MAX = 500000;
vector<int> spf(MAX + 1);

// Build SPF
void buildSieve() {
    for (int i = 2; i <= MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

// Compute sum of proper divisors
long long sumProperDivisors(int n) {
    int N = n;
    long long res = 1;

    while (n > 1) {
        int p = spf[n];
        int alpha = 1;

        while (n % p == 0) {
            n /= p;
            alpha++;
        }

        // Using pow (cast to long long)
        long long term = (long long)(pow(p, alpha) - 1) / (p - 1);

        res *= term;
    }

    return res - N; // proper divisors
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildSieve();

    int n = 20;

    cout << sumProperDivisors_sqrt(n) << endl; // 22
    cout << sumProperDivisors(n) << endl; // 22

    return 0;
}

 