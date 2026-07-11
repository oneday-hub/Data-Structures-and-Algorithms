// lecture 25 ; time lap : 1:7:15
// Arrays as pointers
#include <iostream>
using namespace std; 
int main(){
    int arr[3] = {15, 12, 6};
    int *ptr = &arr[0];
    cout<<ptr<<" "<<arr<<" "<<*arr<<endl; 




    return 0;

}