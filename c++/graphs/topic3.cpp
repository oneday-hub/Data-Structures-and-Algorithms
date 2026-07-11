// topic : Breadth First Search (bfs)

#include <bits/stdc++.h>
using namespace std;
void prepareadj( unordered_map<int, list<int>> &adj,vector<pair<int, int>> &edges){
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}
vector<int> bfs(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareadj(adj,edges);

    // traverse all components of a graph

    for(int i = 0; i<vertex; i++){
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }
    return ans ;
}

int main() {
    
    return 0;
}