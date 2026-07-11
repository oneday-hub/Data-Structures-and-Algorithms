/*         Prims Algorithms : 
---------- Algorithm Steps (CLRS Style) -----------

Given 
G=(V,E):

1. Set key[v] = ∞ for all vertices

2. Pick any start vertex src, set key[src] = 0

3. Push (key, vertex) into a min priority queue

4. While queue is not empty:

   Extract vertex u with minimum key
   Mark u as included in MST
   For every adjacent vertex v of u:

        If v is not in MST and weight(u,v) < key[v]:
            Update key[v]
            Set parent[v] = u

5. The edges (parent[v], v) form the MST.


*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;   // Number of vertices
    vector<vector<pair<int, int>>> adj;
    // adj[u] = { {v, weight}, {v2, weight2}, ... }

public:
    // Constructor
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    // Function to add an undirected weighted edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w}); // u -> v with weight w
        adj[v].push_back({u, w}); // v -> u with weight w (undirected)
    }

    // Prim's Algorithm to find MST
    void primMST(int src) {

        // key[v] = minimum weight edge to connect v to MST
        vector<int> key(V, INT_MAX);

        // parent[v] = parent of v in MST
        vector<int> parent(V, -1);

        // inMST[v] = true if vertex v is already included in MST
        vector<bool> inMST(V, false);

        // Min Priority Queue:
        // pair = (key value, vertex)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // Start from source vertex
        key[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            // Extract vertex with minimum key value
            int u = pq.top().second;
            pq.pop();

            // If already included, skip (important for correctness)
            if (inMST[u] == true)
                continue;

            // Include u in MST
            inMST[u] = true;

            // Traverse all adjacent vertices of u
            for (auto edge : adj[u]) {

                int v = edge.first;   // adjacent vertex
                int weight = edge.second; // weight of edge u-v

                // If v is NOT in MST and current edge is cheaper
                if (inMST[v] == false && weight < key[v]) {

                    // Update the key value
                    key[v] = weight;

                    // Update parent
                    parent[v] = u;

                    // Push the updated key into priority queue
                    pq.push({key[v], v});
                }
            }
        }

        // Print the MST
        int totalCost = 0;
        cout << "\nEdges in the Minimum Spanning Tree:\n";
        cout << "U - V\tWeight\n";

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
                totalCost += key[i];
            }
        }

        cout << "Total cost of MST = " << totalCost << "\n";
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges in format: u v weight (0-based indexing)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter starting vertex for Prim's Algorithm: ";
    cin >> src;

    g.primMST(src);

    return 0;
}
