/*
topic : leetcode : 1691 : Maximum height by stacking cuboids
https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset 
of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

Example 1:

Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

Example 3:
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
*/

#include <bits/stdc++.h>
using namespace std;

// 1. recursion : 

int solve_1(){

}


// 2. recursion + Memo

int solve_2(){

}


// 3. tabulation

int solve_3(){

}

bool check(vector<int> &base, vector<int> &newbox){
    if(nexbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
        return true;
    else
        return false;
}
// 4. space optimization 
int solve_4(int n, vector<vector<int>> &cuboids){


    vector<int> currrow(n + 1, 0);
    vector<int> nextrow(n + 1, 0);


    for(int curr = n -1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= -1; prev--){

            // include
            int include = 0; 

            // using check function for condition 
            if(prev == -1 || check(a[curr], a[prev]))

                // here add the height
                include = cuboids[curr][2] + nextrow[curr + 1];

            // exclude
            int exclude = 0 + nextrow[prev + 1];

            currrow[prev + 1] = max(include, exclude);
        }
        nextrow = currrow;
    }
    return next[0];
}


int maxHeight(vector<vector<int>> &cuboids){
    // step 1 : sort all dimenstion for every cuboid
    for(auto &a : cuboids){
        sort(a.begin(), a.end());
    }

    // step 2 : sort all cuboids basis on width(w) and length(l) 
    // that is base of cuboid

    sort(cuboids.begin(), cuboids.end());

    // step 3 : use LIS logic : 
    return solve_4(cuboids.size(), cuboids);
}

int main() {
    
    return 0;
}