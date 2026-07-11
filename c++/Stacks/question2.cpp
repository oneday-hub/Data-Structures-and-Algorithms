// lecture : 54 ; time : 
/* question 2: insert at bottom / any index
*/

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x){
    /*
    time = o(n)
    space = o(n)
    */
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x); // this is the point where x got inserted at the bottom
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    insertAtBottom(st, 100);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }

    return 0;
}