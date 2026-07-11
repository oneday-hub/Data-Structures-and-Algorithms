#include <iostream>
#include <string>
#include <unordered_set>

bool hasReversedSubstring(const std::string& s) {
    std::unordered_set<std::string> pairs;

    // Iterate through the string and check for pairs of characters
    for (int i = 0; i < s.length() - 1; ++i) {
        std::string pair = s.substr(i, 2);
        std::string reversedPair = std::string(pair.rbegin(), pair.rend());
        if (pairs.find(reversedPair) != pairs.end()) {
            // If the reversed pair is found in the set, return true
            return true;
        } else {
            // Otherwise, add the pair to the set
            pairs.insert(pair);
        }
    }

    // If no matching reversed pair is found, return false
    return false;
}

int main() {
    // Test cases
    std::string s1 = "leetcode"; // No matching substring
    std::string s2 = "abcba";   // Matching substring: "ab"
    std::string s3 = "abcd"; // Matching substring: "ab"

    std::cout << std::boolalpha;
    std::cout << "s1 has reversed substring: " << hasReversedSubstring(s1) << std::endl;
    std::cout << "s2 has reversed substring: " << hasReversedSubstring(s2) << std::endl;
    std::cout << "s3 has reversed substring: " << hasReversedSubstring(s3) << std::endl;

    return 0;
}

