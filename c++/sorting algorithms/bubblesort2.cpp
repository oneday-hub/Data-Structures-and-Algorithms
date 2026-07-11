// lecture no : 35 ; time 54:18
// topic name bubble sort algorithm
// question : how to optimize the bubble sort in the case of nearly 
//            sorted arrays 
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v){
    int n = v.size();
// use the flags
    for( int i = 0 ; i < n-1 ; i++){
        for ( int j = 0 ; j < n-1-i ; j++){
            if ( v[j] > v[j+1] ){
                swap ( v[j], v[j+1]);
            }
        }
    }
    return;
}


int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for ( int i = 0; i<n; i++){
        cin>>v[i];
    }

    bubbleSort(v);
    for(int i = 0 ; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    
}