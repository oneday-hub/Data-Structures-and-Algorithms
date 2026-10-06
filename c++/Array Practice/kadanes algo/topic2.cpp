// Maximum subarray sum

// brute force approach :  o(n2)

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};

    int maxsum = INT_MIN;
    for(int start = 0; start < n; start++){
        int currsum = 0;

        for(int end = start; end < n; end++){
            currsum += arr[end];

            maxsum = max(maxsum, currsum);
        }
    }

    cout << "maximum subarray sum : " << maxsum << endl;
    return 0;
}