// lecture : 48 ; time : 54:14
// topic name : string 
// question : given a string str, sort the given string 
//            constraints : the string will contain only aphabetical 
//                          characters from a-z
//            input 1 : "myworld"
//            output 1 : "dlmorwy"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countSort(string str){

    vector<int> freq(26,0);

    // storing frequency of every character in string
    for(int i =0; i<str.length();i++){
        int index = str[i]-'a';
        freq[index]++;
    }

    //create our sorted string
    int j = 0;
    for(int i =0; i<26; i++){
        while(freq[i]--){
            str[j++] = i + 'a';
        }
    }
    return str;
    
}

int main(){

    string str;
    cin>>str;
    
    cout<<countSort(str)<<endl;

    
    return 0;
}