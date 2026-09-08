class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;

        // Add original index
        for(int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        // Sort by enqueue time
        sort(tasks.begin(), tasks.end());

        // {processing time, index}
        priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;

        long long time = 0;
        int i = 0;

        while(i < n || !pq.empty()) {

            // If no task is available
            if(pq.empty()) {
                time = max(time, (long long)tasks[i][0]);
            }

            // Add all available tasks
            while(i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // Take task with smallest processing time
            int processTime = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            ans.push_back(index);

            // CPU executes task
            time += processTime;
        }

        return ans;

    }
};