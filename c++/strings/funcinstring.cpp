// lecture : 48 ; time  : 23:35
// topic name : commonly used built in functions in string 

#include <iostream>
#include <string>
#include <cstring>

#include <algorithm> // Include for reverse function

using namespace std;

int main() {

    // (1) reverse() function
    // string str = "hello";  
    // reverse(str.begin(), str.end());  
    // cout << str << endl;  

    // (2) substr() function
    // string str = "welcome";
    // cout<<str.substr(0,4)<<endl;
    // cout<<str.substr(1)<<endl;

    // (3) "+" operator
    // string s1 = "my";
    // string s2 = "world";
    // s1+=s2;// s1 = s1+s2
    // cout<<s1<<endl;

    // (4) strcat function 
    // to use strcat function use #include <cstring>
    // char s1[40] = "hello";
    // char s2[40] = "world";
    // strcat(s1,s2);
    // cout<<s1<<endl;

    // (5) push_back() 
    // string s1 = "abcd";
    // char ch = 'e';
    // s1.push_back(ch);
    // cout<<s1<<endl;

    // (6) size()
    // string s1 = "abcde";
    // cout<<s1.size()<<endl;

    // char ch[20] = "abcde";
    // cout<<strlen(ch)<<endl;

    // (7) to_string()
    int num = 432;
    string str = to_string(num);
    str += "1";
    cout<<str[1]<<endl;



    return 0;
}
