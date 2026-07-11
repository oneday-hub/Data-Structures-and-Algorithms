// lecture 58 ; time : 7:23
// topic : Implemenatation of deque
//       -- for refernce :
//       -- https://en.cppreference.com/w/cpp/container/deque

#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    dq.push_front(20);
    dq.push_front(10);
    
    cout<<"The elements of deque : ";
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}