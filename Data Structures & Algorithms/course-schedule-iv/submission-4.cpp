class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for(auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        // reachable[i][j] = true if i is prerequisite of j
        vector<vector<bool>> reachable(
            numCourses,
            vector<bool>(numCourses, false)
        );

        for(int start = 0; start < numCourses; start++) {

            queue<int> q;
            vector<bool> visited(numCourses, false);

            q.push(start);
            visited[start] = true;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int neighbour : adj[node]) {

                    if(!visited[neighbour]) {

                        visited[neighbour] = true;

                        reachable[start][neighbour] = true;

                        q.push(neighbour);
                    }
                }
            }
        }

        vector<bool> output;

        for(auto query : queries) {

            int u = query[0];
            int v = query[1];

            output.push_back(reachable[u][v]);
        }

        return output;
    }
};