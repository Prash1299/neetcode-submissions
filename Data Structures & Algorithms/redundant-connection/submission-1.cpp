class Solution {
public:

    bool solve(int node, vector<bool>& visited, unordered_map<int, vector<int>>& adj, int parent){
        visited[node] = 1;

        for(int i : adj[node]){
            if(!visited[i]){
                bool cycle = solve(i, visited, adj, node);
                if(cycle){
                    return true;
                }
            }

            else if(i != parent){
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for(int i = edges.size()-1; i >= 0; i--){

            int a = edges[i][0];
            int b = edges[i][1];

            edges.erase(edges.begin() + i);
            
            unordered_map<int, vector<int>> adj;

            for(int i = 0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<bool> visited(edges.size()+1 , 0);  

            bool cycle = false;          

            for(int i = 1; i<=edges.size(); i++){
                if(!visited[i]){
                    if(solve(i, visited, adj, -1)){
                        cycle = true;
                        break;
                    }
                }
            }

            if(!cycle){
                return {a, b};
            }

            edges.insert(edges.begin() + i, {a, b});
            
        }

        return {};
    }
};
