
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[0] = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int node = -1;

            // Find the unvisited point with minimum connection cost.
            for (int j = 0; j < n; j++) {
                if (!visited[j] && dist[j] < mini) {
                    mini = dist[j];
                    node = j;
                }
            }

            visited[node] = true;
            sum += mini;

            // Update the minimum cost to connect each unvisited point.
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    int d = abs(points[node][0] - points[j][0])
                          + abs(points[node][1] - points[j][1]);

                    dist[j] = min(dist[j], d);
                }
            }
        }

        return sum;
    }
};
