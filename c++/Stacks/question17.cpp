// lecture : 56 ; time : 
// question : evaluation of prefix expressions
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
    for(int i = str.size() - 1 ; i >= 0; i--){  // corrected loop for evaluation of prefix
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
    string str = "-9+*531";
    cout<<"The evaluated solution : "<<evaluate(str);
    return 0;
}