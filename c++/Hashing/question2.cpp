// lecture : 62 ; time : 0:37
// question : can you make the strings equal?
/*            given an array of strings. you can move any number of characters from one string to 
              any other string any number of times. you just have to make all of them equal.
              print "yes" if you can make every string in the array equal by using any number of operation otherwise print "NO".

              input : ["collegeee", "coll", "collegge"]
              output : yes
              explanation : string at 1 index can take two 'e' from 0 index string and one 'g' from 2 index string.

              input : ["wall", "ah", "wallahah"]
              output : no
              explanation : here we don't have enough number of characters to make all equal.
               
*/ 
#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
bool makeStringEqual(vector<string> &input){
    int n = input.size();
    unordered_map<char, int> freq;
    
    // store the freq of each characters
    for(int i = 0; i<n; i++){
        string str = input[i];
        for(char ch : str){
            freq[ch]++;
        }
    }

    for(auto &pair : freq){
        if(pair.second % n!=0){
            cout<< "No"<<endl;
            return false;
        }
    }
    cout<<"yes"<<endl;
    return true;

}
    
int main(){
    vector<string> input = {"collegeee", "coll", "collegge"};
    cout<<makeStringEqual(input);
    return 0;
}