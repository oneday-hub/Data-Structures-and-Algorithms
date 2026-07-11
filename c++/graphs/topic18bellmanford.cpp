// topic : Bellman ford algo : 


#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges){
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    for(int i = 1; i<=n; i++){
        // traverse on edges list
        for(int j = 0; j<m; j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }


    // check for negative cycle : 
    bool flag = 0;
    
    for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                flag = 1;
            }


        }
        if(flag == 0){
            return dist[dest];
        }
        return -1;

}
int main() {
    int n, m; 
    cout<<"Enter number of vertices : ";
    cin >> n ;

    cout<<"Enter number of edges : ";
    cin >> m; 

    vector<vector<int>> edges(m, vector<int>(3));

    for(int  i =0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    }

    int src, dest;

    cout<<"Enter the source : ";
    cin >> src ;
    
    cout<<"Enter the destination : ";
    cin >> dest;

    int ans = bellmonFord(n, m, src, dest, edges);

    if(ans == -1){
        cout<<"Negative weight cycle present\n";
    }else{
        cout<<"Shortest distance from "<<src
        << " to " << dest << " is : " << ans << endl;
    }
    return 0;
    
}