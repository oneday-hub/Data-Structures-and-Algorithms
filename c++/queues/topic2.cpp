// lecture : 57 ; time : 
// topic : Array implementation of queues
#include<iostream>
#include<vector>
using namespace std;
class Queue{
    int front ;
    int back ;
    vector<int> v;
public:
    Queue(){
        this->front = -1;
        this->back = -1;
    }
    void enqueue(int data){
        v.push_back(data);
        this->back++;
        //this->front++;
        if(this->back == 0) this->front = 0;
    }
    void dequeue(){
        if(this->front == this->back){
            this->front = -1;
            this->back = -1;
            this->v.clear();
        }
        else this->front++;
    }
    int getfront(){
        if(this->front == -1) return -1;
        return this->v[this->front];
    }
    bool isEmpty(){
        return this->front == -1;
    }

};

int main() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);
    while (not qu.isEmpty()) {
        cout << qu.getfront() << endl;
        qu.dequeue();
    }
    return 0;
}
