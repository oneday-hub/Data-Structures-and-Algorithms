/* this is corrected code of leetcode question no 155 stacks 
the solution given by sir is giving answer in some of testcase 
*/


#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> st; // Stack to store values (or differences)
    long long mn; // Current minimum value

    // Constructor: Initialize the minimum value to infinity
    MinStack() {
        mn = LLONG_MAX;
    }

    // Push operation
    void push(int val) {
        if (st.empty()) {
            mn = val; // Update the minimum value
            st.push(0); // Store the difference (val - mn = 0)
        } else {
            st.push((long long)val - mn);
            if (val < mn) {
                mn = val; // Update the minimum value
            }
        }
    }

    // Pop operation
    void pop() {
        if (!st.empty()) {
            long long diff = st.top();
            st.pop();
            if (diff < 0) {
                mn = mn - diff; // Restore the previous minimum
            }
        }
    }

    // Top operation
    int top() {
        if (st.empty()) {
            

        long long diff = st.top();
        if (diff > 0) {
            return mn + diff; // Positive value: Return the adjusted value
        } else {
            return mn; // Negative value: Current minimum is the top element
        }
    }

    // Get minimum operation
    int getMin() {
        if (st.empty()) {
            
        }
        return mn;
    }
};



/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
