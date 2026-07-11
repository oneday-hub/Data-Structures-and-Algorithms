// question : leetcode 121 : Best time to buy and sell stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=dynamic-programming


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int mn = prices[0];
    int profit = 0; 

    for(int i = 1; i < prices.size(); i++){
        profit = max(profit, prices[i] - mn);
        mn = min(mn, prices[i]);
    }
    return profit;
}

int main() {
    int n; 
    cout << "Enter the stocks : ";
    cin >> n; 

    vector<int> prices(n);
    for(int i = 0; i<n; i++){
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;
    return 0;
}