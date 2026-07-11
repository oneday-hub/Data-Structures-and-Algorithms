// lecture : 56 ; time :  58 : 57
// question : evaluation of postfix expression
// Both the time and space complexity is : o(n)
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int calc(int v1, int v2, char op){
    if(op == '^'){
        return pow(v1, v2);
    }
    if(op == '*'){
        return (v1 * v2);
    }
    if(op == '/'){
        return (v1 / v2);
    }
    if(op == '+'){
        return (v1 + v2);
    }
    return (v1 - v2);
}

int evaluate(string &str){
    stack<int> st;
    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(isdigit(ch)){
            st.push(ch - '0');  // 0 here, because to compansate the ascii value
        }else{
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();

            st.push(calc(v1, v2, ch)); // calling the function to calculate the poped characters
        }
    }
    return st.top();
}
int main(){
    string str = "231*+9-";
    cout<<"The evaluated solution : "<<evaluate(str);
    return 0;
}