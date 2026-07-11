// lecture : 58 ; time :
// question : you are given an array of integers nums, there is a sliding window of 
//            size k which is noving from the very left of the array to the right.
//            You can only see the k numbers in the window. Each time the sliding window moves 
//            right by one position. Return the max sliding window which basically contains the max
//            elements in each window.



/*
Detailed Explanation:
Deque Data Structure:

The deque stores the indices of the elements in the array. The element values themselves are not stored, only their indices.
The deque is maintained in descending order, i.e., the largest element in the current window will always be at the front of the deque.
First for loop (Handling the first window):

We iterate over the first k elements.
- Inside this loop, we remove indices from the back of the deque if the element at that index is smaller
 than the current element (arr[i]). This ensures that the deque stores the indices in decreasing order.
- We then add the current index to the deque.
- After processing the first k elements, the front of the deque holds the index of the largest element in 
this window. This value is added to the result vector res.
- Second for loop (Sliding the window):

- We now slide the window by 1 element at a time, from index k to n-1.
- The first thing we do is check if the element at the front of the deque is outside the current window. 
If it is, we remove it. This is done by comparing the index at the front of the deque with (i - k), 
where i is the current index in the loop.
- After that, we repeat the process of removing elements from the back of the deque if they are smaller 
than the current element (arr[i]), ensuring the deque maintains the correct order.
- The current index is then pushed to the back of the deque.
- The largest element of the current window is again at the front of the deque, and it is added to the result vector res.
Result:

The result vector res holds the maximum value for each sliding window of size k.
*/
#include<iostream>
#include<deque>
#include<vector>
using namespace std; 

class Solution {
public:
    // Function to find the maximum element in each sliding window of size 'k'
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        // Deque (double-ended queue) will store indices of elements from the array
        // The front of the deque will always hold the index of the maximum element in the current window
        deque<int> dq;
        
        // This vector will hold the result (maximum values in each window)
        vector<int> res;

        // Loop to process the first window of size 'k'
        for (int i = 0; i < k; i++) {
            // Pop elements from the back of deque if they are smaller than the current element arr[i]
            // This is because we want to ensure the deque stores indices of elements in descending order
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            // Push the current element's index to the deque
            dq.push_back(i);
        }

        // The first window's maximum element is at the front of the deque
        res.push_back(arr[dq.front()]);

        // Loop to process the remaining windows of size 'k'
        for (int i = k; i < arr.size(); i++) {
            // If the element at the front of the deque is outside the current window, pop it
            // (i - k) is the index of the element that is now out of the window
            if (dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from the back of the deque that are smaller than the current element arr[i]
            // These elements are not useful because the current element arr[i] is greater
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            // Push the current element's index to the deque
            dq.push_back(i);

            // The element at the front of the deque is the maximum of the current window
            res.push_back(arr[dq.front()]);
        }

        // Return the result vector containing the maximum elements for each sliding window
        return res;
    }
};
