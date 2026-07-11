// topic 5 : Implementation of tree 

/*

1. Building the tree (using user input recursively)
2. Inorder traversal (left → root → right)
3. Preorder traversal (root → left → right)
4. Postorder traversal (left → right → root)
5. Level-order traversal (BFS using queue)

*/


#include <iostream>
#include <queue>
using namespace std;

// Node class for the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to build the binary tree
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) return NULL;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to print level order traversal line by line

// 4. level order traversal : 
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  // End of current level

            // Add marker for next level if queue is not empty
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// 1. inorder traversal : 
void inOrderTraversal(Node*root){
    if(root == NULL)
    return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

// 2. preorder traversal : 
void preOrderTraversal(Node*root){
    if(root == NULL)
    return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 3. postorder traversal :
void postOrderTraversal(Node*root){
    if(root == NULL)
    return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main() {
    Node* root = NULL;

    // Build the tree
    root = buildTree();
    // 1 3 7 -1 -1 11 -1 -1 5 -1 17 -1 -1

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\n inOrder Traversal:\n";
    inOrderTraversal(root);

    cout << "\n preOrder Traversal:\n";
    preOrderTraversal(root);

    cout << "\n postOrder Traversal:\n";
   postOrderTraversal(root);

    return 0;
}
