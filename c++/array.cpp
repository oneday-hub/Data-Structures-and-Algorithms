#include <iostream>
using namespace std;
//finding the size of array
//this is traversing the arrays
//using loops 
//for loop
int main(){
int array[]={1, 2, 3, 4};
//cout<<sizeof(array)<<endl;
//cout<<"Length of array :" <<sizeof(array)/sizeof(array[0]);
int size = sizeof(array)/sizeof(array[0]);
//for(int idx = 0; idx<size; idx++ ){
 //   cout<<array[idx]<<endl;
//}

//for each loop






//while loop
int index=0;
while(index < size){
    cout<<array[index]<<endl;
    index++;
}







return 0;




}

