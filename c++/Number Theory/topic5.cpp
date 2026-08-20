/*
🧠 Euler’s Totient Function (φ(n))

Euler’s Totient Function counts:

👉 How many numbers from 1 to n are coprime with n

Two numbers are coprime if:

gcd(a,b)=1
*/

#include <bits/stdc++.h>
using namespace std;

// this is basic implementation of Euler's Totient Function 
// using prime factorization 
// T.C = o(sqrt(n));

int phi(int n){
    int res = n; 

    for(int p = 2; p*p <= n; p++){
        if(n % p == 0){
            while(n % p == 0){
                n /= p;
                res -= res /p;
            }
        }
    }
    if(n > 1){
        res -= res /n;
    }
    return res;
}

// you can also solve this problem in : tc : O(n log log(n));
// using sieve algo
    
int main() {
    int t; 
    cout << "Enter the no of test cases : ";
    cin >> t; 
    while(t--){
        int n; 
    cout << "Enter the number : ";
    cin >> n; 

    cout << phi(n) << endl;
    }
    
    return 0;
}

