// question 9 with explaination : vertical traversal of tree 

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Node class representing a tree node
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

// Function to build a binary tree from level order input
Node* buildTree(const vector<int> &v) {
    if (v.empty() || v[0] == -1) return NULL;

    Node* root = new Node(v[0]);     // Create root node
    queue<Node*> q;
    q.push(root);

    int i = 1;
    // Use a queue to build the tree in level order
    while (!q.empty() && i < v.size()) {
        Node* temp = q.front();
        q.pop();

        // Add left child
        if (i < v.size() && v[i] != -1) {
            temp->left = new Node(v[i]);
            q.push(temp->left);
        }
        i++;

        // Add right child
        if (i < v.size() && v[i] != -1) {
            temp->right = new Node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

// Function to return the vertical order traversal of the binary tree
vector<vector<int>> verticalOrder(Node *root) {
    // Nested map:
    // - outer map key: horizontal distance (HD)
    // - inner map key: level (depth)
    // - multiset: nodes at same HD and level (automatically sorted)
    map<int, map<int, multiset<int>>> nodes;

    // Queue stores each node with its horizontal distance and level
    queue<pair<Node*, pair<int, int>>> q;

    // Final answer vector
    vector<vector<int>> ans;

    // Edge case
    if (root == NULL) return ans;

    // Start BFS traversal from root
    q.push({root, {0, 0}});  // root has HD = 0 and level = 0

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;     // horizontal distance
        int level = temp.second.second; // depth level

        // Store the node's data in the correct place in the map
        nodes[hd][level].insert(frontNode->data);

        // Add left child to queue with HD - 1 and level + 1
        if (frontNode->left) {
            q.push({frontNode->left, {hd - 1, level + 1}});
        }

        // Add right child to queue with HD + 1 and level + 1
        if (frontNode->right) {
            q.push({frontNode->right , {hd + 1 , level + 1}});
        }
    }

    // Traverse the map and collect the results
    for (auto &i : nodes) {
        vector<int> col;
        for (auto &j : i.second) {
            // j.second is a multiset, so values are automatically sorted
            for (auto k : j.second) {
                col.push_back(k);
            }
        }
        ans.push_back(col);
    }

    return ans;
}

int main() {
    fast_io;

    // Level order input (-1 represents NULL)
    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};

    // Build the tree
    Node* root = buildTree(v);

    // Perform vertical order traversal
    vector<vector<int>> result = verticalOrder(root);

    // Output the result
    cout << "Vertical Traversal:\n";
    for (const auto &col : result) {
        for (int k : col) {
            cout << k << " ";
        }
        cout << "\n";
    }

    return 0;
}
