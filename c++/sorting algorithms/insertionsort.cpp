// lecture no : 37 ; time : 
// insertion sort algorithm
#include <iostream>
#include <vector>
using namespace std; 

void insertionSort(vector<int> &v){
    int n = v.size();
    

}

int main(){
int n;
cout<<" Enter the no of elements : ";
cin>>n;

vector<int> v(n);
cout<<"unsorted array : ";
for(int i = 0; i<n; i++){
    cin>>v[i];
}

 insertionSort(v);
cout<<"sorted array : ";
for(int i = 0; i<n; i++){
    cout<<v[i]<<" ";
}cout<<endl;

    
return 0;
}