// lecture : 58 ; time : 
// question : we are given a stack data stucture with push and pop operations, 
//            the task is to implement a queue using instances of stack data structure and operations on them.

//            -- using the push() function efficient 

#include<iostream>
#include<queue>
#include<stack>
using namespace std; 

class MyQueue {
public:
    stack<int> inputStack;
    stack<int> outputStack;

    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        if (!outputStack.empty()) {
            int topElement = outputStack.top();
            outputStack.pop();
            return topElement;
        }
        throw runtime_error("Queue is empty!");
    }

    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        if (!outputStack.empty()) {
            return outputStack.top();
        }
        throw runtime_error("Queue is empty!");
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main(){
    return 0;
}