// basics : 


#include <bits/stdc++.h>
using namespace std;
#define ll long long


// 1. Check Prime (isPrime)
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 2. Prime Factors
vector<ll> primeFactors(ll n) {
    vector<ll> factors;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1) factors.push_back(n);

    return factors;
}
// 3. All Factors (Divisors)
vector<ll> getFactors(ll n) {
    vector<ll> factors;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }

    return factors;
}
// 4. Number of Factors
ll numberOfFactors(ll n) {
    ll count = 1;

    for (ll i = 2; i * i <= n; i++) {
        ll power = 0;
        while (n % i == 0) {
            power++;
            n /= i;
        }
        count *= (power + 1);
    }

    if (n > 1) count *= 2;

    return count;
}

// 5. Sum of Factors
ll sumOfFactors(ll n) {
    ll result = 1;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll sum = 1;
            ll term = 1;

            while (n % i == 0) {
                n /= i;
                term *= i;
                sum += term;
            }

            result *= sum;
        }
    }

    if (n > 1) {
        result *= (1 + n);
    }

    return result;
}
// 6. Product of Factors
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll productOfFactors(ll n) {
    ll d = numberOfFactors(n);
    return power(n, d / 2);
}
// 7. Perfect Number
bool isPerfect(ll n) {
    if (n < 2) return false;

    ll sum = 1;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }

    return sum == n;
}

int main() {
    ll n = 36;

    cout << isPrime(n) << endl;

    auto pf = primeFactors(n);
    for (auto x : pf) cout << x << " ";
    cout << endl;

    auto f = getFactors(n);
    for (auto x : f) cout << x << " ";
    cout << endl;

    cout << numberOfFactors(n) << endl;
    cout << sumOfFactors(n) << endl;
    cout << productOfFactors(n) << endl;
    cout << isPerfect(n) << endl;
}