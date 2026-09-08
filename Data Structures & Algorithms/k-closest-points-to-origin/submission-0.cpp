class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // no. of rows
        int n = points.size();

        // no. of columns
        // int m = points[0].size();

        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        int dist = 0;
        for(int i = 0; i < k; i++){

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            pq.push({dist, i});
        }

        for(int i = k; i < n; i++){

            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;

            // Current point is closer than farthest point
            if(dist < pq.top().first){

                pq.pop();
                pq.push({dist, i});
            }
        }

        // Build result
        vector<vector<int>> result;

        while(!pq.empty()){

            int index = pq.top().second;

            result.push_back(points[index]);

            pq.pop();
        }

        return result;


    }
};
