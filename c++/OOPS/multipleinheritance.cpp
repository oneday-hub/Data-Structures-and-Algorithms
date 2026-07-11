// lecture No : 49 ; time : 53:37
// topic name : oops :  Multiple inheritance
#include<iostream>
using namespace std;

class Parent1{
    public:
    Parent1(){
        cout<<"Parent1 class"<<endl;
    }

};
class Parent2{
    public:
    Parent2(){
        cout<<"Parent2 class"<<endl;
    }
};

// here is the example of multiple inheritance

class child: public Parent1, public Parent2{
    public:
    child(){
        cout<<"Child class"<<endl;
    }
};

// This is multi- level inheritance

class Grandchild: public child{
    public:
    Grandchild(){
        cout<<"Grandchild class"<<endl;
    }
};
int main(){
    child c;
    return 0;
}