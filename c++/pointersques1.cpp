// this lecture 25
// Question = call by refernce using pointers
//  void swap (int x, int y){
//     int temp = x; 
//     x=y;
//     y= temp;
//  }
// int main(){
//     int x = 10;
//     int y = 20;
//     swap ( x , y)

//     cout<<x<<" "<<y;
//     return 0;
// }
//output is still x = 10 and y= 20
// why, because primitive likes integer and float they are passed by value 
//let, us see by using pointers
#include <iostream>
using namespace std; 
void swap ( int *x , int *y ){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main (){
    int x = 10;
    int y = 20;
int *p1 = &x; 
int *p2 = &y;

    swap ( p1 , p2);
    cout<<"The value of x : "<< x <<endl<<"The value of y : "<<y;
    return 0;
}