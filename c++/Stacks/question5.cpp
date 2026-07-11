/* lecture : 54 ; time : 
question  : remove at any index 

            iterative method
            and 
            recursive method
*/
#include <iostream>
#include <stack>
using namespace std;

// Function to remove the element at the given index 'idx'
void removeAt(stack<int> &st, int idx) {
    stack<int> temp; // Temporary stack to hold elements
    int n = st.size(); // Total number of elements in the stack
    
    // Step 1: Transfer the top 'n - idx - 1' elements to the temp stack
    while (st.size() > n - idx - 1) {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    
    // Step 2: Remove the element at the 'idx' position
    if (!st.empty()) {
        st.pop();
    }
    
    // Step 3: Transfer the elements back from temp stack to the original stack
    while (!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        st.push(curr); // Push back into the original stack
    }
}

int main() {
    stack<int> st;

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Remove the element at index 1 (0-based index)
    removeAt(st, 1);

    // Print the stack after removal
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }
    return 0;
}
