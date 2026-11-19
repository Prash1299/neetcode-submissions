class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int stop = it.first;
            int node = it.second.first;
            int weight = it.second.second;

            for(auto neighbour : adj[node]){
                int adjnode = neighbour.first;
                int adjweight = neighbour.second;

                if(adjweight + weight < dist[adjnode] && stop <= k){
                    dist[adjnode] = adjweight + weight;
                    pq.push({stop+1, {adjnode, dist[adjnode]}});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};
