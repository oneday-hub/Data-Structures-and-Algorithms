// lecture : 59; time : 1 : 56 : 48
// question : given n intergers (can be duplicates), print the second smallest interger.
//            if it does not exist, print -1
             
/*            
input 1 : n = 4
          1 2 2 -4

output 1 : 1

input 1 : n = 5 
          1 2 3 1 1 

output 2 : 2                      
*/              
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){

    // step 1 :
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    
    // step 2 :
    set<int> s;
    for(auto val : v){
        s.insert(val);
    }
    
    // step 3 :
    auto itr = s.begin();
    itr++;
    cout<<"second smallest interger : "<<*itr<<endl;
    return 0;
}
