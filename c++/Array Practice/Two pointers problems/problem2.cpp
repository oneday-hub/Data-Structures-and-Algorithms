/*
2. Same Direction Pointers (Fast & Slow)

Both move forward.

Used in:

Remove duplicates
Move zeros
Partitioning
Sliding window base

Example: Remove Duplicates
1 1 2 2 3
Idea
i → position to place next unique
j → scans array
🔹 Template
int i = 0;

for(int j = 1; j < n; j++){

    if(arr[j] != arr[i]){
        i++;
        arr[i] = arr[j];
    }
}*/

// question : Remove Duplicates from Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    int i = 0; 

    for(int j = 1; j < n; j++){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}
int main(){
    int n; 
    cout << "Enter the size : ";
    cin >> n; 

    vector<char> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    cout << removeDuplicates(s) << endl;
    return 0;
}