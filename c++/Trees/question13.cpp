// question 13 : lowest common ancestor


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

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

// Function to build a binary tree from level-order input
Node* buildTree(const vector<int>& v) {
    if (v.empty() || v[0] == -1) return NULL;

    Node* root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        Node* temp = q.front();
        q.pop();

        if (i < v.size() && v[i] != -1) {
            temp->left = new Node(v[i]);
            q.push(temp->left);
        }
        i++;

        if (i < v.size() && v[i] != -1) {
            temp->right = new Node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

// Function to find LCA of two nodes in binary tree
Node *lca(Node * root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) return root;

    Node* leftans = lca(root->left, n1, n2);
    Node* rightans = lca(root->right, n1, n2);

    if (leftans && rightans) return root;
    return (leftans != NULL) ? leftans : rightans;
}

int main() {
    fast_io;

    // Tree:        26
    //             /  \
    //           10    3
    //          / \     \
    //         4   6     3

    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};
    Node* root = buildTree(v);

    int n1, n2;
    cout << "Enter two node values to find LCA: ";
    cin >> n1 >> n2;

    Node* ans = lca(root, n1, n2);

    if (ans) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    } else {
        cout << "LCA not found (one or both nodes not in tree)" << endl;
    }

    return 0;
}
