// question : print the permutation of string = "abc" 
// if want the count of the permutations 

#include <iostream>
#include <string>
using namespace std;

void printPermutation(string str, string t, int &count) {
    if (str.empty()) {
        cout << t << endl;
        count++; // to permuate the count too ;
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        string rem = left + right;

        printPermutation(rem, t + ch, count);
    }
}

int main() {
    string str = "abc";
    int count = 0;
    cout << "The permutations are:" << endl;
    printPermutation(str, "", count);
    cout<<"The no of permutations : "<<count<<endl;

    
    return 0;
}
