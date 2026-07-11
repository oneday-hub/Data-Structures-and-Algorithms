//lecture 25 ;  time code: 52:23
//this is case 2 : of post fix 
// topic : pointer arithmetic -> pre and post
#include <iostream>
using namespace std; 
int main(){
    int arr[2] = {5 , 4};
    int *ptr = &arr[0];
    cout<<(*ptr)++<<endl;
    cout<<arr[0]<<" "<<arr[1]<<endl;
    return 0;
}