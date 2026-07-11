// question : delete the node

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; 
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertintobst(Node*root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root -> data){
        root->left = insertintobst(root->left, val);
    }else{
        root->right = insertintobst(root->right, val);
    }
    return root;
}
void takeinput(Node*&root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertintobst(root, data);
        cin >> data;
    }
}
Node* inordersuccessor(Node *root, int data){
    if(root == NULL) return NULL;
    Node*temp = root;


    while(temp!=NULL){
        if(data > temp->data){
            temp = temp ->right;
        }
        return temp;

    }

}
Node* inorderpredecessor(Node* root, int data){
    if(root == NULL) return NULL;
    Node*temp = root;

    while(temp!= NULL){
        if(data < temp->data){
            temp = temp ->left;
        }
        return temp;
    }
}

void inorder(Node *root){
    if(root == NULL)return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    Node*root = NULL;

    cout<<"Enter the data, -1 to stop : ";
    takeinput(root);

    // 100 50 110 25 70 120 60 115 -1
    cout<<"Tree before deleting a node : ";
    inorder(root);
    cout<<endl;

    int data; 
    cout<<"Enter the node :";
    cin>>data;

    cout<<"successor : ";
    inordersuccessor(root, data);

    cout<<"predecessor : ";
    inorderpredecessor(root, data);
    
    return 0;
}