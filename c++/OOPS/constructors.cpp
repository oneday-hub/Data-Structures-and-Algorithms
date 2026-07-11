// lecture no : 49 ; time : 24:33
// topic name : implementation of constructors
#include <iostream>
using namespace std;

class Rectangle {
    public:
    int l ; 
    int b;

    //constructors
    Rectangle(){ // this is default constructors where no arguments are passed
        l = 0;
        b = 0;
    }
    // so this is a parameterised constructors where arguments are passed
    Rectangle(int x , int y){
        l=x;
        b=y;

    }
// this is copy constructor :- initialise an obj by another existing obj
    Rectangle(Rectangle& r){ 
        l = r.l;
        b = r.b;
    }
    
    // Destructors
    ~Rectangle(){ //
        cout<<"Destructor is called " <<endl;
    }


};
int main(){

    Rectangle* r1 = new Rectangle();
    cout<<r1->l<< " " <<r1->b<<endl;
    delete r1; // point to remember : 
               // this delete keyword only be used when pointer variable is used

    Rectangle r2 (3,4);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3 = r2;
    cout<<r3.l<<" "<<r3.b<<endl;
    return 0;
}