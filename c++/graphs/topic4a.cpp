// DFS (Depth First Search) : 

#include <bits/stdc++.h>
using namespace std;

// DFS function to explore all nodes in a connected component
void dfs(int node, unordered_map<int, bool> &visited, 
         unordered_map<int, list<int>> &adj, vector<int> &component) {

    // Add this node to the current connected component
    component.push_back(node);

    // Mark this node as visited
    visited[node] = true;

    // Explore all neighbours of the current node
    for (auto &i : adj[node]) {
        if (!visited[i]) { 
            // If neighbour is not visited → DFS on that node
            dfs(i, visited, adj, component);
        }
    }
}

// Main DFS driver function to find connected components
vector<vector<int>> depthfirstsearch(int v, int e, vector<vector<int>> &edges) {

    // Step 1: Build adjacency list using unordered_map
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0]; // first vertex of edge
        int v = edges[i][1]; // second vertex of edge

        adj[u].push_back(v); // u → v
        adj[v].push_back(u); // v → u (because undirected)
    }

    // To store all connected components
    vector<vector<int>> ans;

    // To mark visited nodes
    unordered_map<int, bool> visited;

    // Step 2: Run DFS for each vertex
    for (int i = 0; i < v; i++) {
        if (!visited[i]) { 
            // If vertex is not visited, create a new component
            vector<int> component;
            dfs(i, visited, adj, component); // DFS fills this component
            ans.push_back(component);        // Store the component
        }
    }

    return ans; // Return all connected components
}

int main() {
    int v;
    cout << "Enter the vertex : ";
    cin >> v;

    int e;
    cout << "Enter the edges : ";
    cin >> e;

    // Example edges → graph may be disconnected
    // Component 1: 0-1-2
    // Component 2: 3-4
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    // Get connected components
    vector<vector<int>> ans = depthfirstsearch(v, e, edges);

    // Output results
    cout << "Connected components:\n";
    for (auto &comp : ans) {
        for (auto node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}
