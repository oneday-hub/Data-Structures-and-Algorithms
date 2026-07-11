// This is lecture  no : 28 
// Question no 2 : given an integer find out the sum of its digits using recursion
#include <iostream>
using namespace std;

int f(int n ){
    //the base case
    if(n<=9 and n>=0){
        return n;
    }
    return f(n/10) + (n%10);
}


int main(){

int result = f(6534);
cout<<result<<endl;


    return 0;
}