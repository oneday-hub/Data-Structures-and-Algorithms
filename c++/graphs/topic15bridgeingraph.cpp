// topic : Bridge in graph : 

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, 
    vector<int> &disc, vector<int> &low,
    vector<vector<int>> &result,
unordered_map<int, bool> &visited,
unordered_map<int , list<int>> &adj){


    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr : adj[node]){
        if(nbr == parent) 
            continue;
        if(!visited[nbr]){
            dfs(nbr, node, timer, disc, low , result, visited, adj);
            low[node] = min(low[node], low[nbr]);

            // check bridge
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }

        }else{
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }

    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){

    // adj list : 
    unordered_map<int , list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0; 
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;

    unordered_map<int, bool> visited;

    for(int i = 0; i<v; i++){
        disc[i] = -1;
        low[i] = -1;

    }

    // dfs
    vector<vector<int>> result;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result,visited, adj);
        }
    }
    return result;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;
    cout << "Enter each edge (u v):\n";

    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;
        edges.push_back({u, vtx});
    }

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "\nBridges in the graph:\n";
    for (auto &b : bridges) {
        cout << b[0] << " -- " << b[1] << "\n";
    }

    return 0;
}
/*
        0
       / \
      /   \
     1-----2
     |
     |
     3
     |
     |
     4
Enter number of vertices: 5
Enter number of edges: 5
Enter each edge (u v):
0 1
1 2
2 0
1 3
3 4

Bridges in the graph:
3 -- 4
1 -- 3
*/