// kadanes algorithms

// most optimised : 

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){

    int currsum = 0;
    int maxsum = INT_MIN;

    for(int i = 0; i < nums.size(); i++){

        currsum += nums[i];
        maxsum = max(maxsum, currsum);

        if(currsum < 0){
            currsum = 0;
        }
    }

    return maxsum;
}

int main() {
    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};

    cout << maxSubArray(nums) << endl;
    return 0;
}