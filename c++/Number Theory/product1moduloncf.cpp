// problem : Product 1 Modulo n : 


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fast_io;
    
    int n; 
    cin >> n; 

    vector<int> coprimes;
    for(int k = 1; k < n; k++){
        if(__gcd(k, n) == 1){
            coprimes.push_back(k);
        }
    }
    ll product = 1; 
    for(int num : coprimes){
        product = (product * num) % n; 
    }

    vector<int> result;
    if(product == 1){
        result = coprimes;
    }else{
        for(int num : coprimes){
            if(num != product){
                result.push_back(num);
            }
        }
    }
    cout << result.size() << endl;
    for(int num : result){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}