//this is lecture 27 recursion
//the recursive code for factorials 
//time lap : 45:44:00
#include <iostream>
using namespace std;
int f (int n){
    //base case
    if (n==1){
        return 1;
}
    //int ans = n * f(n-1);
    //return ans;
    return n * f(n-1); //the above thing can also be written in this form
}


int main(){
    int result = f(5);
    cout<<result<<endl;

return 0;
}