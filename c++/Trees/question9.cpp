// question : vectical traversal of binary tree


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

vector<int> verticalOrder(Node *root){
    //map<int, map<int,vector<int> > > nodes;
    map<int, map<int, multiset<int>>> nodes;
    queue <pair <Node*, pair<int, int> > > q;
    

    if(root == NULL){
        return {};
    
    
    // pairing two things, 1st : Node*root, 2nd : pair of HD and level 
    // HD : Horizontal Distance
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].insert(frontNode->data);
        
        if(frontNode -> left){
            q.push({frontNode->left, {hd - 1, level + 1}});
        }
        if(frontNode -> right){
            q.push({frontNode->right , {hd +1 , level + 1}});
        }
        

    }
    /*
    for (auto &i : nodes)
    This iterates by reference, so i directly refers to the actual elements in the map.
    More efficient: avoids copying, especially useful for large STL containers like:
    map<int, map<int, multiset<int>>>
    */
   vector<vector<int>> ans;
    for(auto &i : nodes){
            //       hd   <int, vector<int>>
            // i = < int, map>
            //       i.first, map = i.second

            for(auto &j : i.second){
                // j = <int, vector<int>>
                //    j.first; j.second

                for(auto k : j.second ){
                    ans.push_back(k);
                }
            }
        }
        return ;
    
    }
}

int main() {
    fast_io;

    vector<int> v = {26, 10, 3, 4, 6, -1, 3, -1, -1, -1, -1};
    Node* root = buildTree(v);

    vector<int> result = verticalOrder(root);
    cout << "Vertical Traversal: ";
    for (int k : result) {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}
