class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;

        for(auto i : mp){
            pq.push(i.second);
        }

        // {remaining frequency, available time}
        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()){

            time++;

            // If a task has finished cooldown
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }

            // Execute a task
            if(!pq.empty()){

                int freq = pq.top();
                pq.pop();

                freq--;

                // If task still has remaining occurrences
                if(freq > 0){
                    q.push({freq, time + n + 1});
                }
            }
        }

        return time;
    }
};
