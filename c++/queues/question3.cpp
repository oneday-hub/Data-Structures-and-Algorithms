// lecture : 58 ; time : 
// question : we are given a stack data stucture with push and pop operations, 
//            the task is to implement a queue using instances of stack data structure and operations on them.

//            -- using the pop() function efficient 
#include<iostream>
#include<queue>
#include<stack>
using namespace std; 
class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        
    }
    
    int pop() {
        int result = st.top();
        st.pop();

        return result;
        
        
    }
    
    int peek() {
        return st.top();
        
    }
    
    bool empty() {
        return st.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(){
    return 0;
}