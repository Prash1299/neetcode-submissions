class Solution {
public:

    bool solve(int node, vector<bool>& visited, vector<bool>& dfsvisited, unordered_map<int, vector<int>>& adj, vector<int>& output){
        visited[node] = 1;
        dfsvisited[node] = 1;

        for(int i : adj[node]){
            if(!visited[i]){
                bool found = solve(i, visited, dfsvisited, adj, output);
                if(found){
                    return true;
                }
            }
            else if(dfsvisited[i]){
                return true;
            }
        }

        dfsvisited[node] = 0;
        output.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<int> output;

        vector<bool> visited(numCourses + 1, 0);

        vector<bool> dfsvisited(numCourses + 1, 0);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool ans = solve(i, visited, dfsvisited, adj, output);

                if(ans){
                    return {};
                }

            }
        }

        // reverse(output.begin(), output.end());

        return output;


    }
};
