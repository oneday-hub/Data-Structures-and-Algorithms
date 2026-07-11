// lecture : 61 ; time : 
// topic : implementation of multimap

#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string, int > directory;
    directory.insert(make_pair("nagendra", 3470809));
    directory.insert(make_pair("satyendra", 4664666));
    directory.insert(make_pair("nagendra", 6850856));
    // directory["urvi"] = 9984738; this is not allowed

    for(auto pair : directory){
        cout<<"name : "<<pair.first<<endl;
        cout<<"name : "<<pair.second<<endl;
    }
    return 0;
}
