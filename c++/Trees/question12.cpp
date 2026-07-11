// question 12 : sum of longest bloodline of a tree,
//              (sum of nodes on the longest path from root to leaf node)

#include <bits/stdc++.h>
using namespace std;

// Fast I/O for competitive programming
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Definition of a Binary Tree Node
class Node {
public:
    int data;
    Node* right;
    Node* left;

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
Recursive function to find:
1. The length of the longest root-to-leaf path.
2. The maximum sum of node values along that path.

Parameters:
- root: current node being visited
- sum: running sum of the path so far
- maxSum: reference to store the final maximum sum (updated if current path is longer or equal but with higher sum)
- len: current length of the path
- maxlen: reference to store the longest path length found so far
*/
void solve(Node* root, int sum, int &maxSum, int len, int &maxlen) {
    // Base case: when we reach a NULL node (end of path)
    if (root == NULL) {
        // Check if the current path is longer than any previously found
        if (len > maxlen) {
            maxlen = len;       // Update the longest length
            maxSum = sum;       // Update the corresponding sum
        }
        // If current path length is equal to maxlen, update maxSum if it's greater
        else if (len == maxlen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    // Add current node's data to sum
    sum = sum + root->data;

    // Recur for left and right subtrees with increased length
    solve(root->left, sum, maxSum, len + 1, maxlen);
    solve(root->right, sum, maxSum, len + 1, maxlen);
}

/*
Main function to start solving the problem.
Initializes necessary variables and calls `solve`.
Returns the maximum sum of the longest root-to-leaf path.
*/
int sumofLongRootToleafPath(Node* root) {
    int len = 0;         // Current path length
    int maxlen = 0;      // Longest path length so far

    int sum = 0;         // Current path sum
    int maxSum = INT_MIN; // Stores the final answer (max sum for longest path)

    solve(root, sum, maxSum, len, maxlen);
    return maxSum;
}

int main() {
    fast_io;

    // Creating the following binary tree:
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6
    // Longest path: 1 -> 2 -> 4 (length 3, sum = 7)
    // Another path: 1 -> 3 -> 5 (length 3, sum = 9) => maxSum = 9
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Sum of the longest root-to-leaf path: " << sumofLongRootToleafPath(root) << endl;

    return 0;
}
