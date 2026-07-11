// question 6 : Sum tree : 

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

pair<bool, int> isSumFastTree(Node *root){
    if(root == NULL){
        return {true, 0};
    }
    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }
    pair<bool, int> left = isSumFastTree(root->left);
    pair<bool, int> right = isSumFastTree(root->right);

    bool sumtree = left.first && right.first && (left.second + right.second) == root->data; 
    int totalsum = left.second + right.second + root->data;

    return {sumtree, totalsum};

}
bool SumTree(Node* root){
        return isSumFastTree(root).first;
    }

int main() {
    fast_io;
    
    //vector<int> v = {1,2,2,3,3,-1,-1,4,4};
    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};


    Node* root = buildTree(v);

    // You can now use this root for any tree operation like traversals, diameter, etc.
    cout<<"ans : "<<SumTree(root)<<endl;
    return 0;
}
