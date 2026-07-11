#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the n number :";

    cin>>n;
    
    int sum=0;

for(int i = 1; i<=n; i++){
    sum+=i;

}
cout<<"sum of the first"  << n <<  "natural numbers :" <<sum<<endl;

return 0;
}