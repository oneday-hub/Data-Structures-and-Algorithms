// topic : Topological Sort using bfs (Kahn's algorithms :)

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // adjacency list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    // compute indegree of each vertex
    vector<int> indegree(v, 0);
    for(auto i : adj) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // push vertices with 0 indegree
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v) 0-based indexing:\n";
    for(int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort: ";
    for(auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}
