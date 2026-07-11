// topic : level Order traveral another approach
/*
Yes! There's a more elegant and cleaner approach to perform level order traversal without using a NULL separator, 
by tracking the number of nodes at each level using a for loop.

✅ Better Approach: Count Nodes Per Level
This version avoids using NULL as a level marker and instead uses the queue size to process one level at a time.
*/
#include <iostream>
#include <queue>
using namespace std;

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

Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
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

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes in the current level

        for (int i = 0; i < levelSize; ++i) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        cout << endl;  // Finished one level
    }
}

// inorder traversal : 
void inOrderTraversal(Node*root){
    if(root == NULL)
    return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


int main() {
    Node* root = buildTree();
    // 1 3 7 -1 -1 11 -1 -1 5 -1 17 -1 -1

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    return 0;
}
