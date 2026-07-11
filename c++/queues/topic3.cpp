// lecture : 57; time : 
// topic : USING INBUILD QUEUES 

#include<iostream>
#include<queue>
using namespace std;
int main(){
    // syntax of queues
    queue<int> qu;

    // to enqueue : 
    qu.push(10);
    qu.push(100);
    qu.push(1000);
    qu.push(10000);

    // to dequeue : 
    qu.pop();
    
    // to print :
    while (! qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}