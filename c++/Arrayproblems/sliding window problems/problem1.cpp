/*Maximum Sum Subarray of Size K
Problem

Given an array and an integer k.

Find the maximum sum among all subarrays of size exactly k.

Example:

nums = [2,1,5,1,3,2]
k = 3

Subarrays of size 3:

[2,1,5] -> 8
[1,5,1] -> 7
[5,1,3] -> 9
[1,3,2] -> 6

Answer:

9
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSumArray(vector<int> &nums, int k){
    int n = nums.size();
    int windowsum = 0;
    // the sum of first window
    for(int i = 0; i < k; i++){
        windowsum += nums[i];
    }

    int ans = windowsum;

    for(int i = k; i < n; i++){
        windowsum += nums[i];
        windowsum -= nums[i - k];

        ans = max(ans, windowsum);
    }
    return ans;
}

int main() {
   vector<int> nums = {2, 1, 5, 1, 3, 2};
   int k = 3;

   cout << "maximum sum subarrays of size exactly k : " << maximumSumArray(nums, k) << endl;
    return 0;
}