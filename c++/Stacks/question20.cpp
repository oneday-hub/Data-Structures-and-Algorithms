// lecture 56 ; time : 
// question : conversion of a prefix expression to a postfix expression 
// prefix = " *+32-15 " --> postfix = " 32+15-* "
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string eval(string &pre){
    stack<string> st;
/*It removes all spaces from the string, ensuring no invalid characters interfere with evaluation.

String Concatenation: The concatenation in string newExp = v1 + v2 + pre[i]; remains valid for postfix 
conversion. For clarity, you can enhance it by adding separators (like spaces).

Input Validation: Ensure only valid prefix expressions are passed into the function.
*/

    pre.erase(remove(pre.begin(), pre.end(), ' '), pre.end()); // above is the explaination of this line 

    reverse(pre.begin(), pre.end());
    for(int i = 0; i<pre.size(); i++){
        if(isdigit(pre[i])){
            st.push(to_string (pre[i] - '0'));
        }else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();

            string newExp = v1 + v2 + pre[i];
            st.push(newExp);
        }
    }
    return st.top();

}
int main(){
    string s = " *+32-15 ";
    cout<< "converted prefix expression to a postfix expression :"<< eval(s);
    return 0;
}