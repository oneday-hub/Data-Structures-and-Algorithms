// lecture : 56 ; time : 

/* question : Design a stack that supports push, pop, top and retrieving the minimun
              element in constant time.
-- Implement the MinStack class : 
> MinStack() intializes the stack object.   
> void push(int val) pushes the element val onto the stack  
> void pop() removes the element on the top of the stack.    
> int top() gets the top element of the stack
> int getMin() retrieves the minimum element in the stack

you must implement a solution with O(1) time complexity for each functions

Assumption : Methods pop, top and getMin operations will always be called on non-empty stacks


*/

 #include<iostream>
 #include<stack>
 using namespace std;

// int main(){
//     return 0;
// }

# define ll long long int
class MinStack {
public:
    stack<ll> st;
    ll  mn;
    MinStack() {
        this -> mn = INT16_MAX; // i.e intiallizing the min = plus infinity
        
    }
    
    void push(int val) {
        if(this -> st.empty()){
            this-> mn = val;
            this -> st.push(val);
        }else{
            this->st.push(val - this -> mn);
            if( val < this -> mn){
                this -> mn = val;

            }
        }
    }
    
    void pop() { // if there is (+ve) element --> no change but if there is (-ve) element there is change in min()
        if(not this -> st.empty()){
            if(this -> st.top() >= 0){
                this -> st.pop();
            }else{
                this->mn = this->mn - this -> st.top();
                this-> st.pop();
            }
        }
    }
    
    int top() {
        if(this -> st.top() == 1){
            return this -> st.top();
        }else if(this->st.top() < 0){
            return this -> mn;
        }else{
            return this ->mn +  this -> st.top();
        }
            
        }
    
    
    int getMin() {
        return this -> mn;
    }
};