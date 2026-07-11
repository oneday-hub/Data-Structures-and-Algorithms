// lecture : 59 ; time : 
// topic : introduction to sets and 
//       : implementation of sets

#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> set1; // in incresing order
    // set<int,greater<int>> set1; // in decresing order
    
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);

    cout<<"The size of set1 : "<<set1.size()<<endl;

    set1.insert(3); 
    // size remains same because duplicate value is added
    // and sets contain only unique values
    
    // Traversal of set :

    // Method (1) :
    // iterator for traversing a set

    set<int> :: iterator i;
    cout<<"printing using iterator : ";
    for(i = set1.begin(); i!= set1.end(); i++){
        cout<<*i<<" ";
    }cout<< endl;
     
    // Method (2) :
    
    // another for printing all the values of set :
    // using for each loop :
    cout<<"printing using for each loop : ";
    for(auto value :set1 ){
        cout<<value<<" ";
    }cout<<endl;

// deletion of elements in 3 methods :
// method (1): 
// set1.erase(4);

// method (2):
// auto itr = set1.begin(); 
// // now to move this itr to 4 use advance() function 
// advance(itr,3);
// set1.erase(itr);

// method (3):
// auto start_itr = set1.begin();
// start_itr++; // now pointing to 2

// auto end_itr = set1.begin();
// advance(end_itr, 3);

// set1.erase(start_itr, end_itr);

   
//    cout<<"printing using for each loop after deletion : ";
//     for(auto value :set1 ){
//         cout<<value<<" ";
//     }cout<<endl;

// Search operation 
if(set1.find(4)!= set1.end()){
    cout<<"value is present"<<endl;
}else{
    cout<<"value is not present"<<endl;
}
    
    return 0;
}
