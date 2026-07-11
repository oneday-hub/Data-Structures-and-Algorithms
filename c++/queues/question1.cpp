// lecture : 57 ; time : 58:38
// question : reverse the queue

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


int main(){
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    
    stack<int> st;
    while(! qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(! st.empty()){
        qu.push(st.top());
        st.pop();
    }
    cout<<"The reversed queue :  ";
    while(! qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();

    }
    return 0;
}