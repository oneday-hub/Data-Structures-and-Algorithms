// lecture 138 : lc : 85 : Maximal Rectangle

/*
Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> &heights, int n) {

        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            int curr = heights[i];

            while (s.top() != -1 &&
                   heights[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    vector<int> previousSmallerElement(vector<int> &arr, int n) {

        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int curr = arr[i];

            while (s.top() != -1 &&
                   arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int> &heights) {

        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);

        vector<int> prev = previousSmallerElement(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {

            int length = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            int breadth = next[i] - prev[i] - 1;

            int newarea = length * breadth;

            area = max(area, newarea);
        }

        return area;
    }


// 1. Recurrsion 
int solve1(){
    // base case

}

int maximalRectangle(vector<vector<char>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();


    int maxi = INT_MIN;
    
    vector<int>rowheight(cols, 0);

    for(int i = 0; i < rows; i++){
        // to create row height in array
        for(int j = 0; j < rowheight.size(); j++){
            if(matrix[i][j] == '1'){
                rowheight[j]++;
            }else{
                rowheight[j] = 0;
            }
        }
        maxi = max(maxi, largestRectangleArea(rowheight));
    }
    return maxi;
}
int main() {
    
    return 0;
}