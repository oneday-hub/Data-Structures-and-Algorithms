/* lecture : 55 ; time :
The type of question : Next greater element
...................imp question..............
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the Next Greater Element (NGE) for each element in the array
vector<int> nge(vector<int> &arr) {
    int n = arr.size();  // Size of the input array
    vector<int> output(n, -1);  // Initialize the output array with -1, meaning no NGE by default

    // Stack to keep track of indexes of elements whose NGE is yet to be found
    stack<int> st;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is greater than the element at the index stored on top of the stack
        while (!st.empty() && arr[i] > arr[st.top()]) {
            output[st.top()] = arr[i];  // Update the NGE for the element at index `st.top()`
            st.pop();  // Remove the index since we have found its NGE
        }
        // Push the current index onto the stack to process later
        st.push(i);
    }

    // At this point, all elements left in the stack do not have a Next Greater Element
    // Since the output array is already initialized to -1, no further changes are needed

    return output;  // Return the vector containing the NGE for each element
}


// Function to find the Previous Greater Element (PGE) for each element in the array
vector<int> pge(vector<int> &arr) {
    int n = arr.size();  // Size of the input array
    vector<int> output(n, -1);  // Initialize output with -1 (no PGE by default)

    // Stack to keep track of elements
    stack<int> st;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Remove elements from the stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the PGE for the current element
        if (!st.empty()) {
            output[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }

    return output;  // Return the vector containing PGE for each element
}

int main() {
    int n; 
    cin >> n;  // Input the size of the array from the user

    // Handle edge case for invalid array size
    if (n <= 0) {
        cout << "Invalid size" << endl;
        return 0;
    }

    vector<int> v;  // Vector to store the input elements
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  // Input each element
        v.push_back(x);  // Add it to the vector
    }

    // Call the function to compute the Next Greater Element for each element in the array
    vector<int> res = nge(v);

    // Output the results
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";  // Print the NGE for each element
    }
    
    return 0;  // Exit the program
}
