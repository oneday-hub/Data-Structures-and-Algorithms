// question : Boundary traversal 


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

// Traverse left boundary (excluding leaf nodes)
void traversalLeft(Node* root, vector<int> &ans){
    if (!root || (root->left == NULL && root->right == NULL)) return;

    ans.push_back(root->data);
    if (root->left)
        traversalLeft(root->left, ans);
    else
        traversalLeft(root->right, ans);
}

// Traverse leaf nodes
void traversalLeaf(Node *root, vector<int> &ans){
    if (!root) return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

// Traverse right boundary (excluding leaf nodes, bottom-up)
void traversalRight(Node* root, vector<int> &ans){
    if (!root || (root->left == NULL && root->right == NULL)) return;

    if (root->right)
        traversalRight(root->right, ans);
    else
        traversalRight(root->left, ans);

    ans.push_back(root->data);  // store after child call (reverse)
}

// Boundary traversal
vector<int> boundary(Node * root){
    vector<int> ans;
    if (!root) return ans;

    ans.push_back(root->data);

    // 1. Left boundary (excluding leaf)
    traversalLeft(root->left, ans);

    // 2. All leaf nodes
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);

    // 3. Right boundary (excluding leaf) in reverse
    vector<int> rightBoundary;
    traversalRight(root->right, rightBoundary);

    ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());

    return ans;
}

int main() {
    fast_io;

    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};
    Node* root = buildTree(v);

    vector<int> result = boundary(root);
    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
