// CLRS-Style DFS for Cycle Detection (Undirected Graph)


#include <bits/stdc++.h>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

bool dfs_cycle(int u, int parent, vector<vector<int>>& adj, vector<Color>& color) {
    color[u] = GRAY;  // visiting

    for (int v : adj[u]) {
        if (color[v] == WHITE) {
            if (dfs_cycle(v, u, adj, color)) return true;
        }
        // if neighbor is visited and not parent -> cycle
        else if (v != parent && color[v] == GRAY) {
            return true;
        }
    }

    color[u] = BLACK; // fully explored
    return false;
}

bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<Color> color(n, WHITE);

    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            if (dfs_cycle(i, -1, adj, color)) return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,3},{3,4},{4,1} // has a cycle
    };

    if (hasCycle(n, edges)) cout << "YES\n";
    else cout << "NO\n";
}
