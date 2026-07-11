// question : burning tree 

// algo : 
// step 1 : create node to parent mapping 
// step 2 : find target node 
// step 3 : burn the tree in min time 


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
Node *createparentmapping(Node* root, int target, map<Node*, Node*>&nodetoparent){
    Node *result = NULL;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }
        if(front -> left){
            nodetoparent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodetoparent[front ->right] = front;
        }
    }
}
void burntree(){

}
int mintime(Node *root, int target){
    int ans = 0;
    map<Node*, Node*>nodetoparent;
    Node* targetnode = createparentmapping(root, target, nodetoparent);

    burntree(targetnode, nodetoparent);
    return ans;
}
int main() {
    fast_io;
    // solution comes here
    
    return 0;
}