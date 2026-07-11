// CLRS BFS → C++ Implementation


// CLRS BFS → C++ Implementation
#include <bits/stdc++.h>
using namespace std;

// Color states for BFS (from CLRS)
// white → undiscovered
// grey  → discovered but not fully explored
// black → fully processed
enum Color { white, grey, black };

// Struct to store all BFS information for a vertex
struct Vertex {
    Color color;  // BFS discovery state
    int dist;     // shortest distance from source vertex
    int parent;   // parent in BFS tree (-1 means NIL)
};

void bfs(int n, vector<vector<int>> &adj, int s) {
    // Create an array of Vertex objects for all nodes
    vector<Vertex> V(n);

    // Step 1–4: Initialize all vertices except the source
    for (int u = 0; u < n; u++) {
        if (u != s) {
            V[u].color = white;       // initially undiscovered
            V[u].dist = INT16_MAX;    // infinity (unreachable yet)
            V[u].parent = -1;         // NIL (no parent assigned)
        }
    }

    // Step 5–7: Initialize source vertex
    V[s].color = grey; // mark as discovered
    V[s].dist = 0;     // distance from source to itself = 0
    V[s].parent = -1;  // root has no parent

    // Step 8–9: Initialize queue and enqueue source vertex
    queue<int> q;
    q.push(s);

    // Step 10–18: BFS main loop
    // While there are discovered but not fully processed vertices (grey)
    while (!q.empty()) {
        // Get and remove the front vertex from the queue
        int u = q.front();
        q.pop();

        // Explore all adjacent vertices of u
        for (int v : adj[u]) {
            // If the neighbor v is undiscovered (white)
            if (V[v].color == white) {
                V[v].color = grey;            // mark as discovered
                V[v].dist = V[u].dist + 1;    // distance = parent's dist + 1
                V[v].parent = u;              // set parent in BFS tree
                q.push(v);                    // enqueue v for later processing
            }
        }
        // After exploring all neighbors of u, mark u as fully processed
        V[u].color = black;
    }

    // Output BFS results
    cout << "vertex\tdist\tparent\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t"
             << (V[i].dist == INT16_MAX ? -1 : V[i].dist) // -1 if unreachable
             << "\t" << V[i].parent << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the no of nodes : ";
    cin >> n;

    // Adjacency list representation of graph
    vector<vector<int>> adj(n);

    // Example undirected graph
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}
    };

    // Build adjacency list (undirected graph → add both directions)
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Run BFS starting from node 0
    bfs(n, adj, 0);

    return 0;
}
