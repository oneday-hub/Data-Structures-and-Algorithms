// topic : introduction to binary search tree (BST)


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* inserttobst(Node *root, int val){
    // base case
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(val > root->data){
        // insert into the right part
        root -> right = inserttobst(root->right, val);
    }else{
        root -> left = inserttobst(root->left, val);
    }
    return root;
}
void takeinput(Node *&root){
    int data;
    cin >> data;
    
    while(data != -1){
        root = inserttobst(root, data); // ← Fixed line
        cin >> data;
    }
}

void levelordertraversal(Node *root){
    if(root == NULL) return ;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<< temp->data << " ";

        if(temp -> left)
        q.push(temp->left);

        if(temp -> right)
        q.push(temp->right);
    }
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    fast_io;
    // solution comes here
    Node* root = NULL;
    
    cout<<"Enter data to create BST :"<<endl;
    takeinput(root);

    // 10 8 21 7 27 5 4 3
    cout<<"levelorder traversal of BST : "<<endl;
    levelordertraversal(root);
    cout<<endl;
    

    cout << "Inorder Traversal: ";
inorder(root);
cout << endl;

cout << "Preorder Traversal: ";
preorder(root);
cout << endl;

cout << "Postorder Traversal: ";
postorder(root);
cout << endl;

    return 0;
}