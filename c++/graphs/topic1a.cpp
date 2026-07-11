#include <bits/stdc++.h>
using namespace std;


int main() {

    int n; 
    cout<<"Enter number of vertex : ";
    cin >> n; 

    int m ; 
    cout<<"Enter number of edges : ";
    cin >> m ;

    vector<vector<int>> undirected(n);
    vector<vector<int>> directed(n);

    for(int i = 0; i<m ;i++){
        int u, v;
        cin >> u >> v; 
        undirected[u].push_back(v);
        undirected[v].push_back(u);
    }


    for(int u = 0; u<n; u++){
        for(int v : undirected[u]){
            directed[u].push_back(v);
        }
    }
    return 0;
}