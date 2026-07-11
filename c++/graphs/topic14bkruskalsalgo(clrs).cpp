// Minimum spanning tree : 
// krushkals algorithms 

/*

Kruskal’s Algorithm (Step-by-Step)
Store all edges in a list
Sort edges by weight
Initialize DSU for all vertices
For each edge (u, v, w) in sorted order:
If find(u) != find(v):
Include this edge in MST
union(u, v)
Stop when MST has V − 1 edges

*/

#include <bits/stdc++.h>
using namespace std;

// --------- DISJOINT SET (UNION FIND) ---------

class DisjointSet {
    vector<int> parent, rank;

public:
    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially, every node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union by rank
    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

// --------- KRUSKAL ALGORITHM ---------

int main() {

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // Edge list: (weight, (u, v))
    vector<pair<int, pair<int, int>>> edges;

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    // Step 1: Sort all edges by weight
    sort(edges.begin(), edges.end());

    // Step 2: Initialize Disjoint Set
    DisjointSet ds(n);

    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    // Step 3: Process edges in increasing order
    for (auto edge : edges) {

        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Step 4: If u and v are in different sets, include the edge
        if (ds.findParent(u) != ds.findParent(v)) {
            ds.unionSet(u, v);
            mstWeight += wt;
            mstEdges.push_back({u, v});
        }
    }

    // Step 5: Print MST
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (auto it : mstEdges) {
        cout << it.first << " - " << it.second << "\n";
    }

    cout << "Total Weight of MST = " << mstWeight << endl;

    return 0;
}
