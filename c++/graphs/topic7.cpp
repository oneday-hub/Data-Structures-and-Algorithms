// topic : topological sort 

#include <bits/stdc++.h>
using namespace std;
void toposort(int vertex, unordered_map<int, bool> &visited, 
    stack<int> &st, unordered_map<int, list<int>> &adj){

        visited[vertex] = true;

        for(auto neighbour : adj[vertex]){
            if(!visited[neighbour]){
                toposort(neighbour, visited, st, adj);
            }
        }
        st.push(vertex);
    }
vector<int> topologicalsort(vector<vector<int>> &edges, int v, int e){
    
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 1; i<=v; i++){
        if(!visited[i]){
            toposort(i, visited, st, adj);
        }
    }
    vector<int> ans ;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main() {
    int vertex ;
    cout<<"Enter the no of vertex : ";
    cin>>vertex;

    int edgecount;
    cout<<"Enter the no of edges : ";
    cin>>edgecount;

    vector<vector<int>> edges(edgecount, vector<int>(2));
    cout << "Enter the edges (u v) : "<<endl;
    for(int i = 0; i<edgecount; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> ans = topologicalsort(edges, vertex, edgecount);

    cout << "Topological Sort : ";
    for(int x : ans) cout<< x << " ";
    cout<<endl; 
    return 0;
}