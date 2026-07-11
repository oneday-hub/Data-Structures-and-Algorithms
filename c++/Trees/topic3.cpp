// topic 5 : Implementation of tree 

// 3. Preorder traversal (root → left → right)

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

// Function to build tree recursively
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    // Base case: -1 means no node (i.e., NULL)
    if (data == -1)
        return NULL;

    // Create a new node
    Node* root = new Node(data);

    // Recursively build the left and right subtrees
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}
void preOrderTraversal(Node*root){
    if(root == NULL)
    return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    // Build the tree
    root = buildTree();

    // You can add traversal functions here to verify the tree
    preOrderTraversal(root);
    return 0;
}
