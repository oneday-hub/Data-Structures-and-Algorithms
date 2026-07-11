// lecture No : 49 ; time : 53:37
// topic name : oops :  hierarchical inheritance
#include<iostream>
using namespace std;

class Parent1{
    public:
    Parent1(){
        cout<<"Parent1 class"<<endl;
    }

};


class child1: public Parent1 {
    public:
    child1(){
        cout<<"Child1 class"<<endl;
    }
};

class child2: public Parent1 {
    public:
    child2(){
        cout<<"Child2 class"<<endl;
    }
};


int main(){
    child1 c;
    child2 d;
    return 0;
}