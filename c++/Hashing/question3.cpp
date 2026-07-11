// lecture : 62 ; time : 17:05
/*
question : check whether two strings are anagram of each other, Return true if they are else return false. 
           An anagram of a string  is another string that contains the same characters, only the order of 
           charachters can be different.
for example : "abcd" and "dabc" are an anagram of each other

input 1 : triangle and integral
output 1 : true 

input 2 : anagram and grams
output 2 : false
*/
#include <iostream>
#include <unordered_map>
using namespace std;

bool checkAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) return false;  // Different lengths can't be anagrams

    unordered_map<char, int> freq;

    // Increase count for str1 and decrease for str2
    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i]]++;
        freq[str2[i]]--;
        // question arise : the loop is for str1 then how the you are decreasing the count of str2
        // ans : The key idea is that both str1 and str2 are of equal length (otherwise, they can't be anagrams). 
        // Since we're iterating over their characters simultaneously using the same index i, we can process
        // both strings in one loop:
    }

    // If all values are 0, it's an anagram
    for (auto &pair : freq) {
        if (pair.second != 0) return false;
    }

    return true;
}

int main() {
    string s1 = "triangle", s2 = "integral";
    cout << (checkAnagram(s1, s2))<< endl; // Expected: true

    string s3 = "anagram", s4 = "grams";
    cout << (checkAnagram(s3, s4) ? "true" : "false") << endl; // Expected: false

    return 0;
}
