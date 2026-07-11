//pattern problem lecture 8 
//finding the sum of digits of the given numbers
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    while (n > 0) {
        int lastdigit = n % 10;
        sum += lastdigit;
        n = n / 10;
    }
    cout << sum <<endl;
    















}