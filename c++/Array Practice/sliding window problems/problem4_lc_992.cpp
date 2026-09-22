/*
problem : Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: 
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 
*/

#include <bits/stdc++.h>
using namespace std;

int atmostk(vector<int> &nums, int k){

    int n = nums.size();
    if(k < 0) return 0;

    unordered_map<int, int> freq;
    
    int left = 0; 
    int count = 0; 

    for(int right = 0; right < n; right++){
        freq[nums[right]]++;

        while(freq.size() > k){
            freq[nums[left]]--;

            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }

            left++;
        }

        count += right - left + 1; 

    }
    return count; 

}
int subarrayWithKDistinct(vector<int> &nums, int k){
    return atmostk(nums, k) - atmostk(nums, k - 1);
}
int main() {
    vector<int> nums = {1,2,1,3,4};
    int k = 3;

    cout << subarrayWithKDistinct(nums, k);
    return 0;
}