class Solution {
public:
    struct Vertex{
        int dist;

    };
    void bfs(int n, vector<vector<int>>&adj, int s){
        vector<Vertex> V;
        vector<bool> isvisited(n, false);

        for(int u = 0 ;u <n ;u++){ // execpt source
            
                V[u].dist = INT_MAX;
            
        }

        V[s].dist = 0;
        isvisited[s] = true;

        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                if(!isvisited[v]){
                isvisited[v] = true;
                V[v].dist = V[u].dist + 1; 
                q.push(v);
                }
            }
        }
        int sumdist = 0;
        for (int i = 0; i < n; i++) {
            sumdist += V[i].dist;
        }
        return sumdist;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> result(n, 0);
     
        for (int i = 0; i < n; i++) {
            result[i] = bfs(n, adj, i);
        }
        return result;
    
    }
};