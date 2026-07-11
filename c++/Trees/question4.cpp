// question 4 : Balanced binary tree


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Define a Node class for the binary tree
class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build a binary tree level order using vector
Node* buildTree(vector<int> &v) {
    if(v.empty() || v[0]==-1) return NULL;

    Node*root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i< v.size()){
        Node*temp = q.front();
        q.pop();

        // left Node
        if(i<v.size() && v[i]!=-1){
            temp->left = new Node(v[i]);
            q.push(temp->left);
        }
        i++;

        // right node
        if(i<v.size() && v[i]!=-1){
            temp->right = new Node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

int height(Node*node){
    if(node == NULL){
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right)+1;
    return ans;
}

bool chechbalancedtree(Node *root){
    if(root == NULL){
        return true;
    }
    bool left = chechbalancedtree(root->left);
    bool right = chechbalancedtree(root->right);

    bool diff = abs(height(root->left) - height(root -> right) <= 1);

    if(left && right && diff){
        return 1;
    }else{
        return false;
    }

}
int chechbalaceOfBinaryTree(Node* root) {
    return chechbalancedtree(root);
}
// the above solution has T.C = O(n2)
// otimized 

    pair<bool, int> checkBalanced(Node* root) {
        if (root == NULL)
            return {true, 0};

        pair<bool, int> left = checkBalanced(root->left);
        pair<bool, int> right = checkBalanced(root->right);

        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = max(left.second, right.second) + 1;

        return {balanced, height};
    }

    bool isBalanced(Node* root) {
        return checkBalanced(root).first;
    }




int main() {
    
    vector<int> v = {1,2,2,3,3,-1,-1,4,4};

    Node* root = buildTree(v);

    // You can now use this root for any tree operation like traversals, diameter, etc.
    cout<<"ans : "<<chechbalaceOfBinaryTree(root)<<endl;
    return 0;
}

    
    
  