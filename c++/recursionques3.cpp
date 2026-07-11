// This is lecture no : 28
// Question no 3 : given two numbers p and q , 
//                 find the value p^q using a recursion function
#include <iostream>
using namespace std;

int f (int p,int q){
    //base case
    if(q==0) {
        return 1;
    }
    return p * f(p , q-1);
}

int main(){
int result = f(12,2);
cout<<result<<endl;
return 0;
}