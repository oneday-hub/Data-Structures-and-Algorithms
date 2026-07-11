//pattern problem 
//lecture 7 pattern loops part 1
// question no 2
#include <iostream>
using namespace std;

int main(){
    int n; 
    cin>> n;
    for( int i = 1; i<=n; i++){
        for( int j = 1; j<=i; j++){
            cout<<"*";

        }
        cout<<endl;
    }
    return 0;
}
   
    