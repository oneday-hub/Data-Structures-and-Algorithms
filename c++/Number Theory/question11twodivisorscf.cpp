// topic : two divisors
// 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// using euclidian algo to find gcd
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void solve(){
    ll a, b; 
    cin >> a >> b; 

    ll res;

    if(b % a == 0){
        res = b * (b / a);
    }else{
        res = a * (b / gcd(a, b));
    }

    cout << res << endl;
}
int main() {
    fast_io;
    int t; 
    cin >> t; 

    while(t--){
        solve();
    }
    
    return 0;
}