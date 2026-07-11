/* lecture : 59 ; time : 
 question : check if string has all english alphabets
            given a string. you have to check if it has all english alphabets from a-z.

            input 1 : abcdefghijklmnopqrstuvwxyz
            output1 : yes
            input 2 : helloworld
            output 2 : no

            explaination : input 1 has all the alphabets in respective of 
                           upper or lower case, so the output is yes, But in input 2 i doesn't 
                           contain all the alphabets, hence no
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Function to check if the string contains all alphabets
bool checkAllAlphabets(string s) {
    if (s.length() < 26) { // If the string has fewer than 26 characters, it cannot contain all alphabets
        return false;
    }
    // std::transform is a function in the C++ Standard Library under the <algorithm> header. 
    // It applies a given function or operation to elements in a range (like arrays, vectors, or strings) 
    // and stores the results in a specified destination.

// sytax :
// 1. For transforming a single range:
// std::transform(InputIterator1 first1, InputIterator1 last1, OutputIterator result, UnaryOperation op);

// 2. For transforming two ranges:
// std::transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation op);


    // Convert the entire string to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Use a set to store unique characters
    set<char> alphabets;
    for (auto ch : s) {
        alphabets.insert(ch); // Insert each character into the set
    }

    // If the set size is 26, the string contains all alphabets
    return (alphabets.size() == 26);
}

int main() {
    string input;
    cout<<"Enter the string : ";
    cin >> input;

    if (checkAllAlphabets(input)) {
        cout << "Yes" << endl; // All alphabets are present
    } else {
        cout << "No" << endl; // Some alphabets are missing
    }

    return 0;
}
