// lecture No : 49 ; time : 17:01
// topic name : basics of oops that is how we use the class and objects

#include <iostream>
using namespace std;
// defining the class
// class class_name{
//     int data1;
//     int data2;
// };
class fruit{ 
    public:
    string name;
    string colour;
};
// class students{
//     string name;
//     int Roll_no ;
    
// };
int main(){
    
    fruit apple; // object
    // the fruit is the datatype and apple is a variable 
    apple.name = "Apple";
    apple.colour = "Red";
    cout <<" The name of the fruit : "<<apple.name<<endl;
    cout << " The colour of the fruit : "<<apple.colour<<endl;

    // another method of defining an object
    fruit *mango = new fruit(); 
    mango->name = "Mango";
    mango->colour = "Yellow";
    cout <<" The name of the fruit : "<<mango->name<<endl;
    cout << " The colour of the fruit : "<<mango->colour<<endl;








    return 0;
}