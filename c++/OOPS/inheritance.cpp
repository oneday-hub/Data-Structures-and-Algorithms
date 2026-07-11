// lecture No : 49 ; time : 36:39
// topic name : oops : inheritance
#include<iostream>
using namespace std;

class Parent{
    public:
    int x;

    protected:
    int y;

    private:
    int z;
};
class child1: public Parent{
    //x will remain public
    //y will remain protected
    //z will not be accessible

};
class child2: private Parent{
    //x will remain private
    //y will remain private
    //z will be inaccessible
};
class child3: protected Parent{
    //x will remain protected
    //y will remain protected
    //z will be inaccessible
};

int main(){
    Parent p;
    p.x;
    cout<<p.x<<endl;
    return 0;

}