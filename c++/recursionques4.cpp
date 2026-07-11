// lecture 29 : time : 20:18
// question : given an array print all the elements of array recursively
#include <iostream>
using namespace std;

void f(int *arr, int idx, int n) {
    // base case
    if (idx == n) return;
    // self work
    cout << arr[idx] << endl;
    // assume that
    f(arr, idx + 1, n);
    //assume it works correctly -> it will print the remaining arr
}

int main() {
    int n = 5;
    int idx = 0;
    int arr[] = {6, 1, 9, 3, 4};
    f(arr, 0, n);
    return 0;
}
