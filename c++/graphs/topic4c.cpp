// CLRS DFS → C++ Implementation with explaination : 


#include <bits/stdc++.h>   // Includes almost all standard C++ libraries
using namespace std;

// Define colors for DFS states
// WHITE = undiscovered, GRAY = discovered but not finished, BLACK = finished
enum Color {WHITE, GRAY, BLACK};

// Structure to hold information about each vertex
struct Vertex {
    int id;        // vertex number (0,1,2,...,V-1)
    Color color;   // current DFS color
    int d;         // discovery time
    int f;         // finish time
    int parent;    // parent vertex in DFS tree
};

// Graph class implementing DFS
class Graph {
    int V;                        // number of vertices
    vector<vector<int>> adj;      // adjacency list: adj[u] contains all neighbors of u
    vector<Vertex> vertices;      // list of vertices with attributes
    int time;                     // global time counter for discovery/finish

public:
    // -------- Constructor --------
    Graph(int n) {
        V = n;                    // set number of vertices
        adj.resize(V);            // create adjacency list of size V
        vertices.resize(V);       // create vertex list of size V

        // Initialize all vertices
        for (int i = 0; i < V; i++) {
            vertices[i].id = i;         // assign vertex id
            vertices[i].color = WHITE; // initially undiscovered
            vertices[i].parent = -1;   // no parent
            vertices[i].d = 0;         // discovery time = 0
            vertices[i].f = 0;         // finish time = 0
        }
        time = 0;   // initialize global clock
    }

    // -------- Add Edge --------
    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge u → v
        // For undirected graph, also add: adj[v].push_back(u);
    }

    // -------- Depth-First Search --------
    void DFS() {
        // Run DFS starting from each WHITE (undiscovered) vertex
        // Ensures even disconnected graphs are covered (DFS forest)
        for (int i = 0; i < V; i++) {
            if (vertices[i].color == WHITE) {
                DFSVisit(i);
            }
        }
    }

    // -------- DFS-Visit --------
    // Recursive function to explore vertex u and its neighbors
    void DFSVisit(int u) {
        time++;                // increase time for discovery
        vertices[u].d = time;  // record discovery time
        vertices[u].color = GRAY; // mark u as discovered (but not finished)

        // Explore all adjacent vertices
        for (int v : adj[u]) {
            if (vertices[v].color == WHITE) {  // if neighbor v is undiscovered
                vertices[v].parent = u;        // set u as parent of v
                DFSVisit(v);                   // recursively visit v
            }
        }

        // After all neighbors are explored
        vertices[u].color = BLACK; // mark u as finished
        time++;                    // increment time for finishing
        vertices[u].f = time;      // record finishing time
    }

    // -------- Print Results --------
    void printResult() {
        cout << "Vertex\tDiscovery\tFinish\tParent\n";
        for (int i = 0; i < V; i++) {
            cout << vertices[i].id << "\t"   // vertex id
                 << vertices[i].d << "\t\t"  // discovery time
                 << vertices[i].f << "\t"    // finish time
                 << (vertices[i].parent == -1 ? -1 : vertices[i].parent) // parent
                 << "\n";
        }
    }
};

// -------- Main Function --------
int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    Graph g(n);  // create graph with n vertices

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v) format (0-based indexing):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v); // add directed edge (u → v)
    }

    // Run Depth-First Search
    g.DFS();

    // Print discovery/finish times and parents
    g.printResult();

    return 0;
}

/*
🌱 The Idea

When we run DFS:

Each vertex gets two timestamps:

Discovery time (d) → when the vertex is first visited (color changes WHITE → GRAY).

Finish time (f) → when we are completely done exploring it (color changes GRAY → BLACK).

Think of it as a stopwatch that ticks whenever DFS makes a move.

Example Graph

Suppose we have this directed graph:

0 → 1 → 3
 \     ↘
  → 2 → 4


Vertices = {0,1,2,3,4}

DFS Walkthrough

Start at 0.
We’ll increase time each time we discover or finish a vertex.

Visit 0

d[0] = 1

Explore neighbors: 1, 2

Go to 1 (neighbor of 0)

d[1] = 2

Explore neighbors: 3

Go to 3 (neighbor of 1)

d[3] = 3

Explore neighbors: (none left unvisited)

Done → f[3] = 4

Back to 1 → done exploring → f[1] = 5

Back to 0 → next neighbor = 2

d[2] = 6

Explore neighbors: 4

Go to 4 (neighbor of 2)

d[4] = 7

No more neighbors → f[4] = 8

Back to 2 → done → f[2] = 9

Back to 0 → done → f[0] = 10

| Vertex | d (Discovery) | f (Finish) | Parent |
| ------ | ------------- | ---------- | ------ |
| 0      | 1             | 10         | -1     |
| 1      | 2             | 5          | 0      |
| 2      | 6             | 9          | 0      |
| 3      | 3             | 4          | 1      |
| 4      | 7             | 8          | 2      |

*/