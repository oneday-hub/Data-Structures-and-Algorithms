// question no 18  : explaination

#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

// Function to perform calculations based on the operator
int calc(int v1, int v2, char op){
    if(op == '^'){ 
        return pow(v1, v2);  // Perform exponentiation
    }
    if(op == '*'){
        return (v1 * v2);  // Perform multiplication
    }
    if(op == '/'){
        return (v1 / v2);  // Perform division
    }
    if(op == '+'){
        return (v1 + v2);  // Perform addition
    }
    return (v1 - v2);      // Perform subtraction
}

// Function to return the precedence of operators
int precedence(char ch){
    if(ch == '^') return 3;                // Exponentiation has the highest precedence
    else if (ch == '*' or ch == '/') return 2; // Multiplication/Division have second-highest precedence
    else if (ch == '+' or ch == '-') return 1; // Addition/Subtraction have lowest precedence
    else return -1;                        // Invalid character
}

// Function to evaluate the mathematical expression
int eval(string &str){
    stack<int> nums;  // Stack to store numbers (operands)
    stack<int> ops;   // Stack to store operators
    
    for(int i = 0; i<str.size(); i++){
        // If the current character is a digit, push it to the nums stack
        if(isdigit(str[i])){
            nums.push(str[i] - '0');  // Convert character to integer and push
        }
        // If the current character is an opening parenthesis '('
        else if(str[i] == '('){
            ops.push('(');  // Push the opening parenthesis onto the operator stack
        }
        // If the current character is a closing parenthesis ')'
        else if(str[i] == ')'){
            // Perform calculations until an opening parenthesis '(' is encountered
            while(not ops.empty() and ops.top() != '('){
                char op = ops.top(); // Get the operator
                ops.pop();           // Remove the operator

                int v2 = nums.top(); // Get the second operand
                nums.pop();
                int v1 = nums.top(); // Get the first operand
                nums.pop();

                nums.push(calc(v1, v2, op)); // Calculate and push the result back onto nums stack
            }
            if(not ops.empty()) ops.pop(); // Pop the '('
        }
        // If the current character is an operator (+, -, *, /, ^)
        else{
            // Perform calculations while the precedence of the current operator
            // is less than or equal to the precedence of the operator at the top of the stack
            while(not ops.empty() and precedence(ops.top()) >= precedence(str[i])){
                char op = ops.top(); // Get the operator
                ops.pop();

                int v2 = nums.top(); // Get the second operand
                nums.pop();
                int v1 = nums.top(); // Get the first operand
                nums.pop();

                nums.push(calc(v1, v2, op)); // Calculate and push the result back onto nums stack
            }
            ops.push(str[i]); // Push the current operator onto the stack
        }
    }

    // After the loop, process any remaining operators in the stack
    while(not ops.empty()){
        char op = ops.top(); // Get the operator
        ops.pop();

        int v2 = nums.top(); // Get the second operand
        nums.pop();
        int v1 = nums.top(); // Get the first operand
        nums.pop();

        nums.push(calc(v1, v2, op)); // Calculate and push the result back onto nums stack
    }
    
    return nums.top(); // The final result will be at the top of the nums stack
}

int main(){
    string str = "1+(2*(3-1))+2"; // Input expression to evaluate
    cout << "The evaluated solution : " << eval(str); // Output the result
    return 0;
}
