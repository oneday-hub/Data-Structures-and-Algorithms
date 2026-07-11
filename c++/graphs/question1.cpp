// question : creating and printing graph
// n = 3 and edges = {{2, 1}, {2, 0}}


#include <bits/stdc++.h>
using namespace std;


class graph{
    public : 

    unordered_map<int, list<int>> adj;

    void addEges(int u, int v, bool direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    void printadjlist(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<< j <<",";
            }
            cout<<endl;
        }
        
    }
};
int main() {
    
    int n; 
    cout<<"Enter no of node : ";
    cin>>n; 

    int m; 
    cout<<"Enter no of edges : ";
    cin>>m;

    graph g;
    for(int i = 0; i<m; i++){
        int u, v; 
        cin>>u>>v; 
        g.addEges(u, v, 0);

    }
    g.printadjlist();
    return 0;
}