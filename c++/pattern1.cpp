//print the rectangular pattern 
//******
//******
//******
//lecture 7 problems on loops part 1
// question no 1
#include <iostream>
using namespace std;
int main (){
    int n,m;
cin>>n;
cin>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<"*";

        }
        cout<<endl;
    }
    return 0;
}
