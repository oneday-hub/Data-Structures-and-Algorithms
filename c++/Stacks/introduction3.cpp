// lecture : 54 ; time : 

/*topic name: introduction to stacks
              
              implementation using the stack header file
              */

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.push(4);
    st.push(6);
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    return 0;


}