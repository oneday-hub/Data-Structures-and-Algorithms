#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    int n, m;
    ll k;

    cin >> n >> m >> k; 

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll g = gcd(n, m);
    ll l = n /g * m;

    int maxval = 2 * max(n, m) + 5;

    vector<ll> posA(maxval, -1);
    for(int i = 0; i < n; i++){
        posA[a[i]] = i;
    }

    vector<ll> sameDays;
    for(int j = 0; j < m; j++){
        int color = b[j];
        if(posA[color] == -1) continue;

        ll t0 = chinese_remainder()
    }

}
int main() {
    fast_io;
    solve ();
    return 0;
}