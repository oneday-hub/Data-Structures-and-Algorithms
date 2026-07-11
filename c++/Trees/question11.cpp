// question 11 : buttom view of tree 


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
vector<int> buttomview(Node* root){

}

int main() {
    fast_io;

    // Level order input (-1 represents NULL)
    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};

    // Build the tree
    Node* root = buildTree(v);

    // Perform vertical order traversal
    //vector<vector<int>> result = buttomview(root);

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
