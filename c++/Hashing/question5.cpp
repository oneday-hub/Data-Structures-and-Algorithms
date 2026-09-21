#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fast_io;
    int t; 
    cin >> t; 
    
    while(t--){
        int a, b; 
        cin >> a >> b; 

        cout << (b - (a%b)) % b << endl;
    }
    return 0;
}