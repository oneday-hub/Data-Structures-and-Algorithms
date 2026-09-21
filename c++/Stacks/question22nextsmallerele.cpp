
#include <bits/stdc++.h>
using namespace std;

// Lecture 56: CodeHelp
// Question: Next Smaller Element

vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {

        int curr = arr[i];

        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextSmallerElement(arr, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}