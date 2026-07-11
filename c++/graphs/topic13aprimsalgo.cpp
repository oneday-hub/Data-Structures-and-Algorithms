// topic : Minimum Spanning Tree 
// (Prim's algorithms)

#include <bits/stdc++.h>
using namespace std;

// Function to calculate Prim's MST
vector<pair<pair<int, int>, int>> calculatePrimsMST(
    int n, int m,
    vector<pair<pair<int, int>, int>> &g
) {
    // Step 1: Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step 2: Initialize arrays
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Step 3: Start from node 1
    key[1] = 0;
    parent[1] = -1;

    // Step 4: Prim's main loop
    for (int i = 1; i < n; i++) {

        int mini = INT_MAX;
        int u = -1;

        // Find minimum key vertex not yet in MST

        // step 1 : find the min wali node : 
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark selected vertex as part of MST

        // step 2 : mark min node as true : 
        mst[u] = true;

        // Relax adjacent vertices
        
        // step 3 : check its adjcent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Step 5: Store MST result
    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}


int main() {

    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<pair<int, int>, int>> edges;

    cout << "Enter edges in format: u v w\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "\nEdges in MST:\n";
    int totalWeight = 0;

    for (auto it : mst) {
        cout << it.first.first << " - "
             << it.first.second << "  Weight = "
             << it.second << endl;
        totalWeight += it.second;
    }

    cout << "Total Weight of MST: " << totalWeight << endl;

    return 0;
}
