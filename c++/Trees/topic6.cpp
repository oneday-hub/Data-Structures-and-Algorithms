// topic 6 : creating a tree from level order traversal

#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL) :"<<endl;
    cin >> data;

    if (data == -1) return NULL;

    Node* root = new Node(data);

    cout << "Enter the left child of " << data << " : ";
    root->left = buildTree();

    cout << "Enter the right child of " << data << " : ";
    root->right = buildTree();

    return root;
}
void buildtreefromLevelOrder(Node*&root){
    queue<Node*> q;
    cout<<"Enter root (-1 for NULL) :"<<endl;
    int data; 
    cin>> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout<<"Enter left child :"<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right child :"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// 1. Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

int main() {
    // Node* root = buildTree();
    // // Sample input: 1 3 7 -1 -1 11 -1 -1 5 -1 17 -1 -1

    // cout << "\nLevel order traversal:\n";
    // levelOrderTraversal(root);

    Node*root = NULL;
    buildtreefromLevelOrder(root);

    return 0;
}
