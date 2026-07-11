#include <iostream>
using namespace std;
//how to take input in array
//lecture 12
int main(){
char vowels [5];
for( int ind = 0; ind<5; ind++){
    cin>>vowels[ind];
}
for( int ind = 0; ind<5; ind++){
    cout<<vowels[ind]<<" ";
}
return 0;
}