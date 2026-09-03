// Lecture 136: Longest Palindromic Subsequence || DP on Strings

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting 
some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

// whole problem logic is : 
// take input string s, reverse it i.e is revs 
// find longest commone subsequence is is longest common palindrome


#include <bits/stdc++.h>
using namespace std;

// space optimization

int solve4(string a, string b){
    int n = a.size();
    int m = b.size();

    vector<int> curr(n+1, 0);
    vector<int> next(m+1, 0);

    for(int i= n-1; i>= 0; i--){
        for(int j = m-1; j>= 0; j--){

            int ans = 0; 

            if(a[i] == b[j]){
                ans = 1 + next[j+1];
            }
            else{
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}


int longestPalindromeSubseq(string s){
    string reverse_s = s;
    reverse(reverse_s.begin(), reverse_s.end());
    int ans = solve4(s, reverse_s);
    return ans;
}

int main() {
    
    
    return 0;
}