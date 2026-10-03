class Solution {
public:

    bool dfs(int node, int parent, vector<bool> &visited, unordered_map<int, vector<int>> &adj){
        visited[node] = 1;
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycle = dfs(neighbour, node, visited, adj);
                if(cycle){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n+1, 0);

        bool ans = dfs(0, -1, visited, adj);

        if(ans){
            return false;
        }

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};
