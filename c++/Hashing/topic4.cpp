// lecture : 61 ; time : 1:33:29
// topic : implementation of unordered multimap using hashing
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string, int>fruitcount;
    fruitcount.insert(make_pair("apple", 4));
    fruitcount.insert(make_pair("banana", 5));
    fruitcount.insert(make_pair("apple", 8));

    for(auto pair: fruitcount){
        cout<<"fruit : "<<pair.first<<endl;
        cout<<"count : "<<pair.second<<endl;
    }
    return 0;
}