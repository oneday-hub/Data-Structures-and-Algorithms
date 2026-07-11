// question 3 : daimeter of tree

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



// diameter is longest path betw any 2 end nodes ie(leaf node/root node)
// ie take the path that has maximum no of nodes is the daimeter

// The optimized version using   pair<int, int> : 

pair<int, int> diameterFast(Node *root){
    //
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    // first block = diameter
    // second block = height

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    // int op1 = diameter(root->left);
    // int op2 = diameter(root->right);
    // int op3 = height(root->left) + height(root->right) + 1;

    pair<int , int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second , right.second) + 1;

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
    //cout<<"The height of binary tree : "<< height(root) <<endl;
    
    cout << "Diameter of the binary tree is: " << diameterFast(root).first << endl;

    return 0;
}
