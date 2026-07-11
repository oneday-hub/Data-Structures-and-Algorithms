/*lecture : 54 ; time : 
question : Remove from Bottom
*/
#include<iostream>
#include<stack>
using namespace std;

// Function to remove the bottom element from a stack
void removeBottom(stack<int> &st){
    stack<int> temp;  // Create a temporary stack to help in the process
    
    // Transfer all elements from 'st' to 'temp' until only the bottom element is left in 'st'
    while(st.size() > 1){  // Loop until only one element (bottom) is left in 'st'
        int curr = st.top();  // Get the top element from 'st'
        st.pop();  // Remove the top element from 'st'
        temp.push(curr);  // Push the element into 'temp'
    }
    
    // Now the bottom element is the only one left in 'st'
    st.pop();  // Remove the bottom element (don't need to store it, just remove)

    // Transfer elements back from 'temp' to 'st' to restore original order (without the bottom element)
    while(!temp.empty()){
        int curr = temp.top();  // Get the top element from 'temp'
        temp.pop();  // Remove it from 'temp'
        st.push(curr);  // Push it back into 'st'
    }
}

int main(){
    stack<int> st;  // Initialize a stack
    // Push elements into the stack
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    removeBottom(st);  // Call the function to remove the bottom element

    // Pop and print the elements of the stack after the bottom element is removed
    while(!st.empty()){
        int curr = st.top();  // Get the top element
        st.pop();  // Remove the top element
        cout << curr << endl;  // Print the element
    }
    return 0;
}
