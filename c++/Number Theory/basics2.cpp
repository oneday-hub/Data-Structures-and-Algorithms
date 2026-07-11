// topic : Sieve of Erotosthenes : 

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;

    for(int i = 2; i <= n; i++){
        if(isprime[i]){
            for(int j = 2*i; j <= n ; j+=i){
                isprime[j] = false;
            }
        }
    }
    return isprime;
}

int main() {
    int n; 
    cout << "Enter the number : ";
    cin >> n; 

    vector<bool> prime = sieve(n);
    for(int i = 2; i <= n; i++){
        if(prime[i]) cout << i << " ";
    }
    return 0;
}