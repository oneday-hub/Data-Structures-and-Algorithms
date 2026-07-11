// Minimum spanning tree : 
// kruskals algorithms : 

#include <bits/stdc++.h>
using namespace std;

// Comparator to sort edges by weight
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

// Make initial set for DSU
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;   // each node is its own parent initially
        rank[i] = 0;     // initial rank is 0
    }
}

// Find parent with path compression
int findParent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    } else {
        // Path compression
        return parent[node] = findParent(parent, parent[node]);
    }
}

// Union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal's MST function
int minimumSpanningTree(vector<vector<int>> &edges, int n) {

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Step 2: Create DSU
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;
    vector<pair<int, int>> mstEdges;

    // Step 3: Pick smallest edges and avoid cycles
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2]; 

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) { //if parent different 
            minWeight += wt;
            mstEdges.push_back({u, v});
            unionSet(pu, pv, parent, rank); // merge 
        }
    }

    // Print MST edges
    cout << "\nEdges in MST:\n";
    for (auto e : mstEdges) {
        cout << e.first << " - " << e.second << endl;
    }

    return minWeight;
}

// ---------------- MAIN FUNCTION ----------------

int main() {

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter edges in format: u v weight (0-based indexing)\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int mstWeight = minimumSpanningTree(edges, n);

    cout << "Total Weight of MST = " << mstWeight << endl;

    return 0;
}
