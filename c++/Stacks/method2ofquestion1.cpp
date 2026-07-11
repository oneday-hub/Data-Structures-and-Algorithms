// lecture : 54 ; time : 
/* question no 1 : copy stacks
                  copy contents of one stack to another in same order
           
           solution 2 : using Recursion 
*/
#include<iostream>
#include<stack>
using namespace std;

// Recursive function to copy the stack
void f(stack<int> &st, stack<int> &result){
    // base case: if the stack is empty, return
    if(st.empty()) return;
    
    // Get the top element
    int curr = st.top();
    st.pop();  // Remove the top element
    
    // Recursively call for the rest of the elements
    f(st, result);
    
    // Add the current element to the result stack
    result.push(curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> res;
    f(st, res);  // Copy the stack using recursion

    // Print the result stack
    while(!res.empty()){
        int curr = res.top();
        res.pop();
        cout << curr << endl;  // Output each element
    }

    return 0;
}
