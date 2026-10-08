class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            for(auto i : adj[node]){
                int adjnode = i.first;
                int adjtime = i.second;

                if(time + adjtime < dist[adjnode]){
                    dist[adjnode] = time + adjtime;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;

    }
};
