// lecture No : 49 ; time : 36:39
// topic name : oops : encapsulation
#include<iostream>
using namespace std;

class ABC{
    int x;

    public:
// this is the function written to get access which is private
    void set(int n){
        x=n;
    }
    int get(){
        return x;
    }
};
int main(){

    ABC obj1;
    obj1.set(3);
    cout<<obj1.get()<<endl;

    return 0;
}