// problem 1 : basic two pointer problem and pattern

/*
Main Types of Two Pointer Problems
1. Opposite Direction Pointers

Pointers start from opposite ends.

left = 0
right = n-1

Used in:

Pair Sum
Palindrome
Container With Most Water
Trapping Rain Water
Example: Pair Sum in Sorted Array

Array:

1 2 3 4 6
target = 6

Process:

left	right	sum
1	6	7 → too big
1	4	5 → too small
2	4	6 ✅
Logic
If sum too small → increase left
If sum too large → decrease right

Because array is sorted.

🔹 Template
while(left < right){

    int sum = arr[left] + arr[right];

    if(sum == target){
        // answer found
    }
    else if(sum < target){
        left++;
    }
    else{
        right--;
    }
}
*/

// Two sum II problem leetcode

#include <bits/stdc++.h>
using namespace std;

vector<int> twosum2(vector<int> &nums, int target){

    int n = nums.size();
    int l = 0; 
    int r = n - 1; 

    while(l < r){
        int sum = nums[l] + nums[r];

        if(sum == target) return{l+1, r+1};

        else if(sum < target) l++;
        else r--;
    }
    return {};
}

int main() {
    int n; 
    cin >> n; 
    vector<int> nums(n);
    cout << "Enter the array element : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int target; 
    cout << "Enter the Target : ";
    cin >> target;

    cout << twosum(nums, target) << endl;
    
    return 0;
}