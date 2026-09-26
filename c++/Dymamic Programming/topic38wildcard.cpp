// lecture 139 : wildcard pattern matching

/*
Given an input string (s) and a pattern (p), implement wildcard pattern 
matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', 
which does not match 'b'.
*/

#include <bits/stdc++.h>
using namespace std;


// 1. Recurrsion
int solve1(string &str, string &pattern, int i, int j){

    // base case

    // case 1
    if(i < 0 && j < 0){
        return true;
    }

    // case 2
    if(i >= 0 && j < 0){
        return false;
    }

    // case 3
    if(i < 0 && j >= 0){
        for(int k = 0; k <= j; k++){
            if(pattern[k] != '*'){
                return false;
            }
        }
        return true;
    }

    // match
    
    if(str[i] == pattern[j] || pattern[j] == '?'){
        return solve1(str, pattern, i-1, j-1);
    }else if(pattern[j] == '*'){

        return ( solve1(str, pattern, i, j-1) || // -> for '*' - > empty string
                 solve1(str, pattern, i-1, j))   // -> for replacing '*' with '*'x
    }else{ // doesnt match
        return false;
    }
}


// 2. Recurrsion + memo

int solve2(string &str, string &pattern, int i, int j, vector<vector<int>> &dp){

    // base case
    if(i < 0 && j < 0){
        return true;
    }

    if(i >= 0 && j < 0){
        return false;
    }

    if(i < 0 && j >= 0){
        for(int k = 0; k <= j; k++){
            if(pattern[j] != '*'){
                return false;
            }
        }
        return true;
    }

    // match condition

    if(str[i] == pattern[j] || pattern[j] == '?'){
        return solve2(str, pattern, i-1, j-1, dp);
    }else if(pattern[j] == '*'){
        // case 1 : replace * with empty string
        return (solve2(str, pattern, i, j-1, dp) || 
        // case 2 : replace * with *x
               solve2(str, pattern, i-1, j, dp));
    }else{
        return false;
    }
}


// 3. tabulation

int solve3(string str, string pattern){
    vector<vector<int>> dp(str.size()+1, vector<int>(pattern.size()+1, 0));

    // looking at the base case of ------  recurrsion

    // step 1
    dp[0][0] = true;

    // step 2 is handled in while making the dp vector i.e assigned false(0)

    // step 3 : 
    for(int j = 1; j < pattern.size(); j++){
        bool flag = true;
        for(int k = 1; k <= j; k++){
            if(pattern[k] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= pattern.size(); j++){

            if(str[i] == pattern[j] || pattern[j] == '?'){
                dp[i][j] = dp[i-1][j-1];

            }else if(pattern[j] == '*'){
                // case 1 : replace * with empty string // case 2 : replace * with *x

                dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
        
            }else{
                dp[i][j] = false;
            }
        }
        dp[str.size()][pattern.size()];
    }

}
bool isMatch(string s, string p){
    return solve1(s, p, s.size()-1, p.size()-1);

    
}

int main() {
    
    
    return 0;
}