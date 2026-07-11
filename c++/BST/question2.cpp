// question : Search in BST : 

#include <bits/stdc++.h>
using namespace std;


class Node {
public: 
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

bool searchBST(Node *root, int x) {
    if (root == NULL) {
        return false;
    }

    if (root->data == x)
        return true;

    if (root->data > x) {
        return searchBST(root->left, x);
    } else {
        return searchBST(root->right, x);
    }
}

int main() {
    

    Node* root = NULL;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    if (n > 0) {
        cout << "Enter " << n << " values: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insertBST(root, val);
        }
    } else {
        cout << "BST is empty.\n";
    }

    int x;
    cout << "Enter value to search in BST: ";
    cin >> x;

    if (searchBST(root, x)) {
        cout << "Value " << x << " found in BST.\n";
    } else {
        cout << "Value " << x << " not found in BST.\n";
    }

    return 0;
}
