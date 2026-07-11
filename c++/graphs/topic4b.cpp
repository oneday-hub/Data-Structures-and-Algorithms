// CLRS DFS → C++ Implementation

#include <bits/stdc++.h>
using namespace std;

enum Color {white, grey, black};

struct Vertex{
    int id;
    Color Color;
    int d; 
    int f; 
    int parent;
};

class Graph{
    int V;
    vector<vector<int>> adj; 
    vector<Vertex> vertices;
    int time ;

    public : 
    Graph(int n){
        V = n;
        adj.resize(V);
        vertices.resize(V);

        for(int i = 0; i < V; i++){
            vertices[i].id = i;
            vertices[i].Color = white;
            vertices[i].parent = -1;
            vertices[i].d = vertices[i].f = 0;
            
        }
        time = 0;
    }

    void addedges(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(){
        for(int i = 0; i < V; i++){
            if(vertices[i].Color == white){
                dfs_visit(i);
            }
        }
    }

    void dfs_visit(int u){
        time ++;
        vertices[u].d = time ; 
        vertices[u].Color = grey;

        for(auto v : adj[u]){
            if(vertices[v].Color == white){
                vertices[v].parent = u;
                dfs_visit(v);
            }
        }

        vertices[u].Color = black;
        time ++;
        vertices[u].f = time ;
    }

    void print_result(){
        cout<<"Vertex\tDiscovery\tFinish\tParent\n";
        for(int i = 0; i < V; i++){
            cout << vertices[i].id << "\t"
                 <<  vertices[i].d << "\t\t"
                 <<  vertices[i].f << "\t"
                 <<  (vertices[i].parent == -1 ? -1 : vertices[i].parent) << "\n";
        }
    }

};

int main() {
    int n; 
    cout << "Enter the no of vertices : ";
    cin >> n; 

    int m ; 
    cout << "Enter the no of edges : ";
    cin >> m; 

    Graph g(n);

    cout << "Enter edges (u v) : "<<endl;
    for(int i = 0; i<m; i++){
        int u , v; 
        cin >> u >> v;

        g.addedges(u, v);
    }

    g.dfs();
    g.print_result();

    return 0;
}