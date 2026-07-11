// topic : cycle dectection in undirected graph :


#include <bits/stdc++.h>
using namespace std;

bool iscyclicbfs(int src, unordered_map<int , bool> &visited, 
                 unordered_map<int , list<int>> &adj , unordered_map<int, int> &parent){

    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto nei : adj[front]){
            if(visited[nei] && nei != parent[front]){
                return true ;  // cycle found
            }
            else if(!visited[nei]){
                q.push(nei);
                visited[nei] = true;
                parent[nei] = front;
            }
        }
    }
    return false;
}

string cycle_detection(vector<vector<int>> &edges, int n, int m){
    // adjacency list
    unordered_map<int , list<int>> adj;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // check all components
    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
            bool ans = iscyclicbfs(i, visited, adj, parent);
            if(ans) return "YES";
        }
    }
    return "NO";
}

int main() {
    int n = 5, m = 5;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{4,1}  // cycle exists
    };

    cout << cycle_detection(edges, n, m) << endl;
    return 0;
}
