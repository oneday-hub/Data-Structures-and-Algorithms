// lecture 29 : time : 47:41
// question : print the max value of the array [3, 10, 3, 2, 5]
#include <iostream>
using namespace std;
int f (int *arr, int idx, int n){
    //base cade
    if(idx == n-1){
        //we only have one element left , so it is the maximum
        return arr[idx];
    }
    return max(arr[idx], f(arr, idx+1, n));
}

int main(){
int arr[] = { 13, 10, 3, 2, 5};
int n = 5;
cout<<f(arr, 0, n);

    
    return 0;
}