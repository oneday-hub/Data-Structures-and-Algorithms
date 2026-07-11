// lecture no : 38 ; time 
// topic name : problem solving on sorting algorithms 

// ques : given an integer array arr move all 0's to the end of it 
//        while maintaining the relative order of the non-zero 
//        elements (note) : note that you must do this in place
//        without making a copy of the array
#include <iostream>
#include <vector>
using namespace std;

void swapZerostoEnd(vector<int> &v){

    int n = v.size();
    for( int i=n-1;i>=0; i--){
        int j=0;
        bool flag = false;

        while(j!=i){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
                flag = true;
            }
            j++;

        }
        if(!flag) break;
    }
    return;

}

int main(){

    int n; 
    cout << "Enter the no elements : " ; 
    cin>>n;

    vector<int> v(n);  
    for(int i= 0; i<n; i++) {
        cin>>v[i];
    }

    swapZerostoEnd(v);
    cout<<"sorted array : ";
    for(int i = 0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
}