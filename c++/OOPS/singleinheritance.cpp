// lecture No : 49 ; time : 50:37
// topic name : oops :  single inheritance
#include<iostream>
using namespace std;

class Parent{
    public:
    Parent(){
        cout<<"Parent class"<<endl;
    }

};
class child: public Parent{
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
    Grandchild gc;
    return 0;
}
