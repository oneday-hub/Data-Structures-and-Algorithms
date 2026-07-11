// question : insert in the BST 

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
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node *searchBST(Node *root, int key){
    if(root == NULL) return NULL;

    if(key == root -> data) return root ;

    if(key < root -> data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);

    
}
void inorder(Node *root){
    if(root  == NULL) return ;
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root -> right);

}
int main() {
    fast_io;
    // solution comes here
    
    return 0;
}


