//this lecture 24 basic explanation of pointer
#include <iostream>
using namespace std;
int main(){
int x = 68;
float y = 7.8;

//create a pointer that can store address of x;
//As x is an integer variable , so er need a pointer
//that can store address of integer type
int *ptr1 = &x;
cout<<ptr1<<endl;

//create a pointer that can store address of y
//y is a float variable , so wr need a pointer
//float pointer
float *ptr2 = &y;
cout<<ptr2<<endl;


}