#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve(){
    int n, k; 
    cin >> n >> k; 

    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    ll lcm = 1;
    for(int i = 0; i < n; i++){
        ll g = gcd(lcm, c[i]);
        ll mul = c[i]/g;
        lcm = (lcm * mul) % k;

        if(lcm % k == 0){
            cout << "YES" << endl;
            return ;
        }
    }

    if(lcm % k == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
int main() {
    fast_io;
    
    solve();
    
    return 0;
}