class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int maxVal = it.first;
            int currx = it.second.first;
            int curry = it.second.second;

            if(currx == row-1 && curry == col-1){
                return maxVal;
            }

            if (maxVal > dist[currx][curry]) {
                continue;
            }

            // iterate on 4 directons

            if(currx + 1 < row){
                int newVal = max(maxVal, grid[currx+1][curry]);
                if(newVal < dist[currx+1][curry]){
                    dist[currx+1][curry] = newVal;
                    pq.push({newVal, {currx+1, curry}});
                }
            }

            if(curry + 1 < col){
                int newVal = max(maxVal, grid[currx][curry+1]);
                if(newVal < dist[currx][curry+1]){
                    dist[currx][curry+1] = newVal;
                    pq.push({newVal, {currx, curry+1}});
                }
            }

            if(currx - 1 >= 0){
                int newVal = max(maxVal, grid[currx-1][curry]);
                if(newVal < dist[currx-1][curry]){
                    dist[currx-1][curry] = newVal;
                    pq.push({newVal, {currx-1, curry}});
                }
            }

            if(curry - 1 >= 0){
                int newVal = max(maxVal, grid[currx][curry-1]);
                if(newVal < dist[currx][curry-1]){
                    dist[currx][curry-1] = newVal;
                    pq.push({newVal, {currx, curry-1}});
                }
            }
        }

        return 0;
    }
};
