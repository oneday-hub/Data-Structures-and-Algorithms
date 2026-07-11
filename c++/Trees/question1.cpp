// question : count the leaf node
#include<iostream>
using namespace std;

// Define a Node class for the binary tree
class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build a binary tree using recursion
Node* buildTree() {
    int data;
    cout << "Enter root (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to count the number of leaf nodes
int countLeafNodes(Node* root) {
    // Base case: empty tree
    if (root == NULL)
        return 0;

    // If it's a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Build the tree
    Node* root = buildTree();

    // Example input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    // Tree structure:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //
    // Expected output: 3 (leaf nodes are 4, 5, 3)

    cout << "\nNumber of leaf nodes: " << countLeafNodes(root) << endl;
    return 0;
}
