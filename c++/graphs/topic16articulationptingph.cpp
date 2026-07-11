// topic : Articulation point in graph : 

#include <bits/stdc++.h>
using namespace std;


int main() {
   vector<pair<int, int>> edges;
   edges.push_back(make_pair(0,3));
   edges.push_back(make_pair(3,4));
   edges.push_back(make_pair(0,4));
   edges.push_back(make_pair(0,1));
   edges.push_back(make_pair(1,2));
   
   // adj list : 
   unordered_map<int, list<int>> adj;
   for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   int timer = 0;
   vector<int> disc(n);
   vector<int> low(n);
   unordered_map<int, bool> visited;
   vector<int> ap(n,0);

   for(int i = 0; i<n; i++){
    disc[i] = -1;
    low[i] = -1;
   }
   for(int i = 0; i<n; i++){
    if(!visited[i]){
        dfs(i, -1, disc, low, visited, adj, ap, timer);
    }
   }

   // print articulation point (AP):
   cout<< "Articulation point are as follows : " << endl;
   for(int i = 0; i<n; i++){
    if(ap[i] != 0){
        cout<< i << " ";
    }
   }cout<<endl;
    return 0;
}