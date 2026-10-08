class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 

        pq.push({0, {0, 0}});

        dist[0][0] = 0;

        while(!pq.empty()){
            int diff = pq.top().first;
            int currx = pq.top().second.first;
            int curry = pq.top().second.second;

            pq.pop();

            if(currx == row - 1 && curry == col - 1){
                return diff;
            }

            if(currx + 1 < row){
                int neweffort = max(abs(heights[currx][curry] - heights[currx+1][curry]), diff);
                if(neweffort < dist[currx+1][curry]){
                    dist[currx+1][curry] = neweffort;
                    pq.push({neweffort, {currx+1, curry}});
                }
            }

            if(curry + 1 < col){
                int neweffort = max(abs(heights[currx][curry] - heights[currx][curry+1]), diff);
                if(neweffort < dist[currx][curry+1]){
                    dist[currx][curry+1] = neweffort;
                    pq.push({neweffort, {currx, curry+1}});
                }
            }

            if(currx - 1 >= 0){
                int neweffort = max(abs(heights[currx][curry] - heights[currx-1][curry]), diff);
                if(neweffort < dist[currx-1][curry]){
                    dist[currx-1][curry] = neweffort;
                    pq.push({neweffort, {currx-1, curry}});
                }
            }

            if(curry - 1 >= 0){
                int neweffort = max(abs(heights[currx][curry] - heights[currx][curry-1]), diff);
                if(neweffort < dist[currx][curry-1]){
                    dist[currx][curry-1] = neweffort;
                    pq.push({neweffort, {currx, curry-1}});
                }
            }

        }

        return 0;
    }
};