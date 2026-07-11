// question : Max/Min value in BST 

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node*inserttobst(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = inserttobst(root->left, val);
    }else{
        root->right = inserttobst(root->right, val);
    }
    return root;
}
void takeinput(Node*&root){
    int data;
    cin >> data;

    while(data != -1){
        root = inserttobst(root, data);
        cin >> data;
    }
}
Node* min(Node *root){
    if(root == NULL){
        return NULL;
    }
    Node*temp = root;
    while(temp->left != NULL){
        temp = temp ->left;
    }
    return temp;
}

Node*max(Node *root){
    if(root == NULL){
        return NULL;
    }
    Node*temp = root;
    while(temp->right!= NULL){
        temp = temp -> right;
    }
    return temp;
}

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root ->right);
}

int main() {
    Node *root = NULL;

    cout<<"Enter the data untill -1 : ";
    takeinput(root);

    cout<<"Inorder traversal : "<<endl;
    inorder(root);
    cout<<endl;

    Node*minvalue = min(root);
    Node*maxvalue = max(root);

    if(minvalue!=NULL){
        cout<<"The minimum value : "<<minvalue->data<<endl;
    }
    if(maxvalue!=NULL){
        cout<<"The maximum value : "<<maxvalue->data<<endl;
    }
    return 0;
}

