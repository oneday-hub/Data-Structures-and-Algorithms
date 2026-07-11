// cycle detection in undirected graph using dfs : 

#include <bits/stdc++.h>
using namespace std;

// DFS function to detect cycle in an undirected graph
bool dfs_cycle(int u, int parent, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs_cycle(v, u, adj, visited)) 
                return true;
        } 
        else if (v != parent) {
            // If the neighbor is visited and not the parent, cycle exists
            return true;
        }
    }
    return false;
}

// Function to check if the graph has a cycle
bool hascycle(int n, vector<vector<int>> &edges) {
    // Prepare adjacency list using unordered_map
    unordered_map<int, vector<int>> adj;
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs_cycle(i, -1, adj, visited)) 
                return true;
        }
    }
    return false;
}

int main() {
    int n = 5; // number of nodes
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // contains a cycle
    };

    if (hascycle(n, edges))
        cout << "YES, CYCLE DETECTED\n";
    else
        cout << "NO, no cycle\n";

    return 0;
}
