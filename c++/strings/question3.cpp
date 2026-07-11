// lecture : 48 ; time : 1:49:55
// topic name : string 
/* question : given an array of string write a program to find the 
              longest common prefix string amongest an array of string
              input : ["flower", "flight", "flask"]
              output : "fl"

*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std; 

string LongestCommonPrefix(vector<string> &str){
    //sorting the array of strings 
    sort(str.begin(),str.end());

    string s1 = str[0]; // first string
    int i = 0;
    string s2 = str[str.size()-1]; // last string
    int j = 0;

    string ans = "";
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            ans += s1[i];
            i++; j++;
        }
        else{
            break;
        }
    }
    return ans ;
}


int main(){

    int n;
    cout<<"Enter no of strings : ";
    cin>>n;

    cout<<"Enter strings :";
    vector<string> str(n);
    for(int i = 0; i<n; i++){
        cin>>str[i];
    }

    cout<<"Longest common prefix : "<<LongestCommonPrefix(str)<<endl;


    return 0;
}