// all loops problems 
// also pattern problems
#include <iostream>
using namespace std;
//while loop
//print the sum of first n natural no where n is the input
int main(){
    int n;
    cin>>n;
    int sum=0;

    
    
    int i=1; //loop variable
    while(i<=n){
        sum+=i;
        i++;

    }
cout<<sum<<endl;

return 0;




}