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

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

        pq.push({{0, src}, k+1});

        dist[src][k+1] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int price = it.first.first;
            int node = it.first.second;
            int stop = it.second;

            if(node == dst){
                return price;
            }

            if(stop == 0){
                continue;
            }

            for(auto i : adj[node]){
                int adjnode = i.first;
                int adjprice = i.second;

                int newReminingstop = stop-1;

                if(price + adjprice < dist[adjnode][newReminingstop]){
                    dist[adjnode][newReminingstop] = price + adjprice;
                    pq.push({{dist[adjnode][newReminingstop], adjnode}, newReminingstop});
                }
            }

        }

        return -1;

    }
};
