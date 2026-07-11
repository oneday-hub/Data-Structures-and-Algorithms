// topic : kosaraju's algo : 

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, 
    unordered_map<int, list<int>> &adj){

        visited[node] = true;
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr, visited, st, adj);
            }
        }
        // topological sort
        st.push(node);
}


void revdfs(int node, unordered_map<int, bool> &visited,
            unordered_map<int, list<int>> &adj){

    visited[node] = true;   // ⭐ REQUIRED
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            revdfs(nbr, visited, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
    
    // adj list : 
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }


    stack<int> st;
    unordered_map<int, bool> visited;
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(i, visited, st, adj);
        }
    }

    // create a transpose graph : 
    unordered_map<int, list<int>> transpose;
    for(int i = 0; i<v; i++){
        visited[i] = 0;
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above ordering : 

    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(!visited[top]){
            count++;
            revdfs(top, visited, transpose);
        }
    }

    return count;
}

int main() {
  int v, e; 

  cout<<"Enter number of vertices : ";
  cin >> v; 

  cout<<"Enter number of edges : ";
  cin >> e; 

  vector<vector<int>> edges;
  cout<<"Enter edges (u v):\n";
  for(int i = 0; i < e; i++){
    int u, w;
    cin >> u >> w;
    edges.push_back({u, w});
  }

  int result = stronglyConnectedComponents(v, edges);
  cout<<"Number of Strongly Connected Components : "<< result << endl;

    return 0;
}