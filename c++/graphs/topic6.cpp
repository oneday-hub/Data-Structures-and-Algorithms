// cycle detection in directed graph : 

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool dfs_cycle(int u, unordered_map<int, list<int> > &adj, unordered_map<int, int > &visited, 
    unordered_map<int, int > &dfsvisited) {

        visited[u] = true; 
        dfsvisited[u] = true; // mark node in recursion stack

        for(auto v : adj[u]){
            if(!visited[v]){
                //cycle found
                if(dfs_cycle(v, adj, visited, dfsvisited)) return true;
            }
            else if(dfsvisited[v]){
                // back-edge found -> cycle
                return true;
            }
        }
        dfsvisited[u] = false; // remove from recusion stack
        return false;
    }

bool hascycle(int n, vector<vector<int>> &edges){

    // adjacency list : 
    unordered_map<int, list<int> > adj;
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }

    unordered_map<int, int > visited, dfsvisited;

    // check all nodes (components of graphs : )
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            if(dfs_cycle(i, adj, visited, dfsvisited)) return true;
        }
    }
    return false;

}

int main() {
    int n = 4; // number of nodes (0 to 3)

    // Example: Directed graph with cycle
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}
    };

    if (hascycle(n, edges)) cout << "Cycle Detected\n";
    else cout << "No Cycle\n";

    return 0;
}
