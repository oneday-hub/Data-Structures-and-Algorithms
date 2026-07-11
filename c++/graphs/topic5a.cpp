// Code (C++ BFS Cycle Detection – CLRS style)

#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a cycle starting from "start" using BFS
bool bfs_cycle_check(int start, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited) {
    // parent map to keep track of the node from which we reached the current node
    unordered_map<int, int> parent;

    // BFS queue
    queue<int> q;
    visited[start] = true;   // mark start as visited
    parent[start] = -1;      // start has no parent
    q.push(start);           // push start into queue

    while (!q.empty()) {
        int u = q.front();   // get front node
        q.pop();

        // Traverse all neighbors of u
        for (int v : adj[u]) {
            if (!visited[v]) {
                // If neighbor v is not visited → visit it
                visited[v] = true;
                parent[v] = u;    // track parent of v
                q.push(v);
            }
            else if (parent[u] != v) {
                // If neighbor v is already visited and
                // v is not parent of u → cycle found
                return true;
            }
        }
    }
    return false; // No cycle detected in this component
}

// Main cycle detection function for an undirected graph
bool hasCycle(int n, vector<vector<int>> &edges) {
    // Build adjacency list using unordered_map
    unordered_map<int, vector<int>> adj;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // because graph is undirected
    }

    // Visited map to keep track of visited nodes
    unordered_map<int, bool> visited;

    // Graph may be disconnected → check every component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (bfs_cycle_check(i, adj, visited)) {
                return true;  // cycle found in some component
            }
        }
    }
    return false; // no cycle in any component
}

int main() {
    int n = 5; // number of nodes (0 to 4)

    // List of edges (undirected graph)
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // this contains a cycle
    };

    // Run cycle detection
    if (hasCycle(n, edges)) cout << "Cycle Detected\n";
    else cout << "No Cycle\n";

    return 0;
}
