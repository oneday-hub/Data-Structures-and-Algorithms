/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

// method : 1

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include<iostream>
#include<vector>
using namespace std;
void backtrak(vector<int> &nums , vector<int> &empty, vector<bool> &isvalid, vector<vector<int>> &ans ){
    if(nums.size() == empty.size()){
        ans.push_back(empty);
        return;
    }
    for(int i = 0; i<nums.size(); i++){
        if(isvalid[i] == false){ // isvalid means if [F, F, F] then only call
            empty.push_back(nums[i]);
            isvalid[i] = true;

            backtrak(nums, empty, isvalid, ans);

            isvalid[i] = false;
            empty.pop_back();
        }
    }
}


vector<vector<int>> permutate(vector<int> &nums){
vector<vector<int>> ans;
vector<int> empty;
vector<bool> isvalid(nums.size(), false);
backtrak(nums, empty, isvalid, ans);
return ans;

}
int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permutate(nums);

    for(auto &perm : permutations){
        for(int val : perm){
            cout << val <<" ";
        }cout << endl;
    }
    
    return 0;
}