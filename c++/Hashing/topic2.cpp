// lecture : 61 ; time : 1:33:29
// topic : implementation of unordered map using hashing
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int, string> records;
    // roll no, name
    records.insert(make_pair(3, "narry"));
    records[1] = "bali";
    records[2] = "hali";
    records[3] = "kushi";

    for(auto pair: records){
        cout<<"Roll NO : "<<pair.first<<endl;
        cout<<"Name : "<<pair.second<<endl;
    }

    return 0;
}