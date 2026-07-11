// question : permutation (method 2)

// Given an array nums of distinct integers, return all the possible permutations. 
// You can return the answer in any order.

#include <bits/stdc++.h>
 using namespace std;
 int main() {
 long long x = 1; 
 long long n = 7;
 long long m = 3;
 for(int i = 2; i<=n ; i++){
    x = (x*i)%m;
 }
 cout<<x%m<<"\n";
 }