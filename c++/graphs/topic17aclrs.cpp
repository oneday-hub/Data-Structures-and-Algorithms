#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj) {
        visited[node] = true;
        for(int nbr : adj[node]) {
            if(!visited[nbr]) {
                dfs1(nbr, visited, st, adj);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<bool> &visited, vector<int> &component, vector<vector<int>> &revAdj) {
        visited[node] = true;
        component.push_back(node);

        for(int nbr : revAdj[node]) {
            if(!visited[nbr]) {
                dfs2(nbr, visited, component, revAdj);
            }
        }
    }

    vector<vector<int>> kosaraju(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> visited(n, false);
        stack<int> st;

        // Step 1: DFS to fill stack
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                dfs1(i, visited, st, adj);
        }

        // Step 2: Reverse graph
        vector<vector<int>> revAdj(n);
        for(int u = 0; u < n; u++) {
            for(int v : adj[u]) {
                revAdj[v].push_back(u);
            }
        }

        // Step 3: DFS using stack order
        /*
        for(int i = 0; i < visited.size(); i++) {
        visited[i] = false;
        }
        */
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> result;

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!visited[node]) {
                vector<int> component;
                dfs2(node, visited, component, revAdj);
                result.push_back(component);
            }
        }
        return result;
    }



int main() {
    int n, m; 
    cout << "Enter the number of nodes : ";
    cin >> n; 

    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> edges;
    cout << "Enter each edge (u v):\n";

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v; 
        edges.push_back({u, v});
    }

    vector<vector<int>> result = kosaraju(n, edges);

    cout << "Strongly Connected Components:\n";
    for(int i = 0; i < result.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for(int node : result[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
