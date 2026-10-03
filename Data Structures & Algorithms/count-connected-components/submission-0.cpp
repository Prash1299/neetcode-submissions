class Solution {
public:

    int dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj){
        visited[node] = 1;

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, adj);
            }
        }

        return 1;

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n+1, 0);

        int ans = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans = ans + dfs(i, visited, adj);
            }
        }

        return ans;

    }
};
