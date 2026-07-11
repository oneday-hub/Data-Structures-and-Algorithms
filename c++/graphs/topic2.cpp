// topic 2 : metrix representation of graph


// unweighted grapgh : 

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter the no nodes : ";
    cin>>n;

    int m; 
    cout<<"Enter the no of edges : ";
    cin>>m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for(int i = 0; i<m; i++){
        int u, v; 
        cin>>u>>v;

        adj[u][v] = 1; 
        adj[v][u] = 1; 

    }
    cout<<"Adjacency Matrix : ";
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            cout<<adj[i][j] <<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}