class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       greater<vector<int>>> pq;

        // Store: {from, to, passengers}
        for(int i = 0; i < trips.size(); i++) {
            pq.push({trips[i][1], trips[i][2], trips[i][0]});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> drop;

        int passengers = 0;

        while(!pq.empty()) {

            int from = pq.top()[0];
            int to = pq.top()[1];
            int count = pq.top()[2];

            pq.pop();

            // Remove passengers whose trip has ended
            while(!drop.empty() && drop.top().first <= from) {
                passengers -= drop.top().second;
                drop.pop();
            }

            // Add new passengers
            passengers += count;

            if(passengers > capacity)
                return false;

            // Store {dropLocation, passengers}
            drop.push({to, count});
        }

        return true;
    }
};