// question 10 : top view of tree

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

// Function to compute top view of the tree
vector<int> TopView(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    // hd (horizontal distance) -> node value
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Insert into map if horizontal distance is not yet present
        if (m.find(hd) == m.end()) {
            m[hd] = frontNode->data;
        }

        // Push left and right children with updated HD
        if (frontNode->left)
            q.push({frontNode->left, hd - 1});
        if (frontNode->right)
            q.push({frontNode->right, hd + 1});
    }

    // Extract values in order of increasing HD
    for (auto &i : m) {
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    fast_io;

    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};
    Node* root = buildTree(v);

    vector<int> result = TopView(root);
    cout << "Top View: ";
    for (int k : result) {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}
