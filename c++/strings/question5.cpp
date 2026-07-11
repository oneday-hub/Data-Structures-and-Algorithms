// lecture : 48 ; time : 
// topic name : string 

/* question : An encoded string(s) is given, and the task is to decode it
             The encoding pattern is that the occurrence of the starting at 
             the starting of the string and each string is enclosed by square 
             brackets 
        Note : The Occurrence of a single string is less than 1000.

        input : s = 1[b]
        output : b

        input : s = 3[b2[ca]]
        output : bcacabcacabcaca

*/
#include<iostream> 
#include<string>
using namespace std;

string decodedString(string s){

    string result = "";

    //traversing the encoded string
    for(int i = 0; i<s.length();i++){

        if(s[i]!=']'){
            result.push_back(s[i]);
        }
        else{

            //extract str from the result
            string str = "";
            

        }
    }
}

int main(){
    string str;
    cin>>str;

    cout<<decodedString(str)<<endl;
    return 0;
}