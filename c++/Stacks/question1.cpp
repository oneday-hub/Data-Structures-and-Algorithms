/*lecture : 54 ; time : 

question : copy stack
           copy contents of one stack to another in same order
           
           solution 1 : using iterative 
            */
#include<iostream>
#include<stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(not input.empty()){
        // do the process till the time input stack doesnt become empty
        int curr = input.top(); // [] curr =1 
        input.pop();
        temp.push(curr); // [3,2,1]
    }
    stack<int> result;
    while(not temp.empty()){
         int curr = temp.top();
         temp.pop();
         result.push(curr);
    }

    return result;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> res = copyStack(st);
// to print
    while (not res.empty())
    {
        int curr = res.top();
        res.pop();
        cout<<curr<<endl;
    }
    return 0;
}       