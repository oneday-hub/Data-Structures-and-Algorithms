// question 2 : height of binary tree


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
int height(Node*node){
    if(node == NULL){
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right)+1;
    return ans;
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
    cout<<"The height of binary tree : "<< height(root) <<endl;
    
    return 0;
}
