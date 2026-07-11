/* lecture : 54 ; time : 
question  : remove at any index 

            recursive method
*/

#include <iostream>
#include <stack>
using namespace std;

// Recursive function to remove the element at a specific index
void removeAtRecursive(stack<int> &st, int idx) {
    // Base case: If the stack is empty or index reaches 0, remove the top element
    if (idx == 0) {
        st.pop(); // Remove the top element
        return;
    }

    // Save the top element
    int topElement = st.top();
    st.pop();

    // Recursive call to process the next element
    removeAtRecursive(st, idx - 1);

    // Push the stored element back onto the stack
    st.push(topElement);
}

int main() {
    stack<int> st;

    // Push elements onto the stack
    st.push(4); // Top of stack
    st.push(3);
    st.push(2);
    st.push(1); // Bottom of stack

    // int indexToRemove = 1; // 0-based index

    // Call the recursive function to remove the element at index 1
    removeAtRecursive(st, 1 );//indexToRemove);

    // Print the stack after removal
    //cout << "Stack after removing element at index " << indexToRemove << ":\n";
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
