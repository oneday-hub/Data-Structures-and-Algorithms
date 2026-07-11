// question 3(b) : Daimeter of Binary 

// you can implement the diameter problem using a vector-based level-order input, 
// instead of interactive input. 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node{
    public:
    int v;
    Node *left;
    Node *right;
    Node(int val){
        v = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree from vector (level order input)
Node* buildTree(const vector<int>& v) {
    if (v.empty() || v[0] == -1) return nullptr;

    Node* root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < v.size()) {
        Node* temp = q.front();
        q.pop();

        // Left child
        if (i < v.size() && v[i] != -1) {
            temp->left = new Node(v[i]);
            q.push(temp->left);
        }
        i++;

        // Right child
        if (i < v.size() && v[i] != -1) {
            temp->right = new Node(v[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

// Optimized diameter calculation using pair<int, int>
pair<int, int> diameterFast(Node* root) {
    if (!root) return {0, 0};  // {diameter, height}

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int height = 1 + max(left.second, right.second);
    int diameter = max({left.first, right.first, left.second + right.second});

    return {diameter, height};
}

int diameterOfBinaryTree(Node* root) {
    return diameterFast(root).first;
}

// Main function
int main() {
    // Level order input for the tree: -1 represents NULL
    vector<int> levelOrder = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};

    Node* root = buildTree(levelOrder);

    cout << "Diameter of the tree is: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
