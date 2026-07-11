// lecture : 59; time : 1:34:52
// topic : introduction to multiset
#include<iostream>
#include<set>
using namespace std; 

int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    for(auto value : ms){
        cout<<value<<" ";
    }cout<<endl;

    return 0;
}
