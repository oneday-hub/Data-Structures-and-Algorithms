/* lecture : 54 ; time : 
question : insert at any Index 
*/
#include<iostream>
#include<stack>
using namespace std;

// Function to insert an element at a specific index in the stack
void insertAt(stack<int> &st, int x, int idx){
    stack<int> temp; // Temporary stack to hold elements while manipulating the original stack
    int n = st.size(); // Get the current size of the stack
    int count = 0; // Counter to track the position

    // Pop elements from 'st' and push them into 'temp' until the desired index is reached
    while(count < n - idx){ 
        count++; // Increase the count
        int curr = st.top(); // Get the top element of the original stack
        st.pop(); // Remove the top element from the original stack
        temp.push(curr); // Push the removed element onto the temporary stack
    }

    // Now, push the new element 'x' into the original stack at the desired index
    st.push(x);

    // Push back all the elements from 'temp' into 'st' to restore the original order
    while(!temp.empty()){
        int curr = temp.top(); // Get the top element from the temporary stack
        temp.pop(); // Remove the element from the temporary stack
        st.push(curr); // Push it back into the original stack
    }
}

int main(){
    stack<int> st;
    // Pushing initial values into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // Insert the value 100 at index 1 (counting from the bottom of the stack)
    insertAt(st, 100, 1);

    // Pop and print the elements of the stack
    while(!st.empty()){
        int curr = st.top(); // Get the top element of the stack
        st.pop(); // Remove the top element
        cout << curr << endl; // Print the element
    }

    return 0;
}
