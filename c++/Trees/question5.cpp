// question 5 : identical tree
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

// Build tree using level-order data
Node* buildTree(const vector<int> &v) {
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

// Function to check if two trees are identical
bool isIdentical(Node* p, Node* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->data != q->data) return false;

    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

int main() {
    fast_io;

    // Input: [1,2,3]
    vector<int> tree1 = {1, 2, 3};
    vector<int> tree2 = {1, 2, 3};

    Node* root1 = buildTree(tree1);
    Node* root2 = buildTree(tree2);

    if (isIdentical(root1, root2)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
