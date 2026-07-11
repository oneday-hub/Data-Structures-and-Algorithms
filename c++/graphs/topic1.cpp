// question : introduction to graphs :

#include<iostream>
#include<list>
#include <unordered_map>

using namespace std;
template <typename T>
class graph{
    public : 
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
    // direction = 0 -> undirected
    // direction = 1 -> directed graph

    // create an edge from u to v

    adj[u].push_back(v);

    if(direction == 0){
        adj[v].push_back(u); // because undirected graph
    }

}
void printadjlist(){
    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
}
    
};
int main(){
    int n; 
    cout<<"Enter the no of nodes : ";
    cin>>n; 

    int m; 
    cout<<"Enter the no of edges : ";
    cin>>m; 
    
    graph<int> g;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        //creating undirected graph
        g.addEdge(u, v, 0);
    }
    //printing the graph

    g.printadjlist();
   

    return 0;
}