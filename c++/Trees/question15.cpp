// question : construct binary tree from inorder and preorder traversal 

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int findposition(vector<int> &inorder, int element, int n){
    for(int i = 0; i<n; i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}
Node *solve(vector<int> &preorder, vector<int> &inorder, int index, int inorderstart, int inorderend, int n){
    // base case : 
    if(index >= n || inorderstart > inorderend){
        return NULL;
    }
    int element = preorder[index++];
    Node *root = new Node(element);

    int position = findposition(inorder,element,n);

    // the recurrsive calls : 

    root->left = solve(preorder, inorder, index, inorderstart, position - 1, n);
    root->right = solve(preorder, inorder, index,position + 1, inorderend, n);

    return root;

}
Node *buildtree(vector<int> &preorder, vector<int> &inorder){
    int n = inorder.size();
    int preorderindex = 0;
    return solve(preorder,inorder,preorderindex, 0 , n-1, n);
    
}
void printinorder(Node *root){
    if(root == NULL){
        return ;
    }
    printinorder(root->left);
    cout<< root->data <<" ";
    printinorder(root->right);
}
int main() {
    fast_io;
    // solution comes here
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node *root = buildtree(preorder, inorder);

    cout<<"Inorder traversal of constructed tree : ";
    printinorder(root);
    return 0;
}