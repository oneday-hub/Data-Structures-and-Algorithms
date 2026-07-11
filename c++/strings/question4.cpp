// lecture : 48 ; time : 2:03:20
// topic name : string 
/* question : given an array of string write a program to find the 
              longest common prefix string amongest an array of string
              input : ["flower", "flight", "flask"]
              output : "fl"

              Another method : not using the sorting to reduce the time
                               complexity

*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std; 

string LongestCommonPrefix(vector<string> &str){
    
    // keeping first string as const and comparing it with all other strings
    string s1 = str[0];
    int ans_length = s1.size();

    for(int i = 1; i<str.size(); i++){

        int j = 0;

        // finding the common prefix string length
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j])
        j++;

        ans_length = min(ans_length,j); // upadating length of ans string


    }
    string ans = s1.substr(0,ans_length);
    return ans;


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


