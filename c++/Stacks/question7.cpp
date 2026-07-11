/* lecture : 54 ; time : 1:55:00
question  : reverse the stack
            iterative solution
*/
#include<iostream>
#include<stack>
using namespace std;
void reverse(stack<int> &st){
    stack<int> t1, t2;
    // moving from st to t1
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }
    // moving from t1 to t2
    while (!t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    // moving from t2 to st
    while (!t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}
int main(){
    stack<int> st;

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); // top
    reverse (st);
    while (!st.empty()){
        int curr = st.top();
        st.pop();
        cout<< curr <<endl;
    }
    

    return 0;
}