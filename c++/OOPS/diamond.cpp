// lecture No : 49 ; time : 57:48
// topic name : oops :  Dioamond problem
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

class grandchild: public child1, public child2{
    public:
    grandchild(){
        cout<<"grandchild class"<<endl;
    }
};



int main(){
    grandchild gc;
    return 0;
}
// if you look parent1 class is called 2 times and this is called diamond problem

/*Parent1 class
Child1 class
Parent1 class
Child2 class
grandchild class*/