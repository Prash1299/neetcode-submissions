class Solution {
public:
    string reorganizeString(string s) {

        string ans;
        int l = s.length();

        unordered_map<char, int> mp;

        int n = 1; // Atleast 1 gap

        // Count frequency
        for(int i = 0; i < l; i++) {
            mp[s[i]]++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for(auto i : mp) {
            maxFreq = max(maxFreq, i.second);
        }

        // Impossible to reorganize
        if(maxFreq > (l + 1) / 2) {
            return "";
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for(auto i : mp) {
            pq.push({i.second, i.first});
        }

        // {frequency, availableTime, character}
        queue<tuple<int, int, char>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // Move task from cooldown queue to heap
            if(!q.empty() && get<1>(q.front()) == time) {

                pq.push({get<0>(q.front()), get<2>(q.front())});

                q.pop();
            }

            // Execute character
            if(!pq.empty()) {

                int freq = pq.top().first;
                char alpha = pq.top().second;

                pq.pop();

                ans.push_back(alpha);

                freq--;

                // Put character into cooldown
                if(freq > 0) {
                    q.push({freq, time + n + 1, alpha});
                }
            }
        }

        // If we couldn't use all characters
        if(ans.length() != l) {
            return "";
        }

        return ans;
    }
};